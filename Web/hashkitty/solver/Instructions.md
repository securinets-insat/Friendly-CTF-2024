

# **HashKitty Writeup**

## **Introduction**
Upon opening the task, we notice that there's a hardcoded hash for the admin password, which is a really REALLY bad thing to do.

Hardcoded means that the password hash is in the app code itself and not in a database, for example.

After studying a little bit about what hashes are and further reading the code to see that the username is `admin` and that the hashing algorithm is SHA-256, we can form some hypotheses about what we can do.

Since hashes are not directly reversible, we can only (for now) use the same hashing algorithm on a bunch of popular passwords and see if it's the same hash.

Thankfully, we have a tool for that, and it's called Hashcat, hence the name Hashkitty.

## **Installing Hashcat**
By installing Hashcat using your package manager or downloading it from the official [Hashcat website](https://hashcat.net/hashcat/), you can start the cracking process.

### **Step 1: Identify the Hash Algorithm**
We already know from the code that the hashing algorithm is **SHA-256**. Therefore, we need to tell Hashcat to use this algorithm when attempting to crack the hash.

### **Step 2: Preparing to Crack the Hash**
First, we need to save the hash into a file. Create a file called `hash.txt` and add the hardcoded hash from the code:
```
b31f2c047e442f9e88f27ab3742c18d8a305d43ac034c6b0f65fb095260c5a7a
```

### **Step 3: Finding a Suitable Wordlist**
Hashcat can use a wordlist (a file with a list of potential passwords) to attempt cracking the hash. One commonly used wordlist is `rockyou.txt`, which can be found online or within many Linux distributions like Kali Linux in the `/usr/share/wordlists/` directory.

### **Step 4: Running Hashcat**
Now that we have our hash and wordlist, let's run Hashcat. Open your terminal and execute the following command:

```bash
hashcat -m 1400 hash.txt /path/to/wordlist/rockyou.txt --show
```

Explanation:
- `-m 1400`: Specifies the hash type (1400 corresponds to SHA-256).
- `hash.txt`: The file containing our target hash.
- `/path/to/wordlist/rockyou.txt`: The path to your wordlist.
- `--show`: shows the output in the CLI

### **Step 5: Analyzing the Results**
Hashcat will attempt to match the hash in `hash.txt` against hashes of words in `rockyou.txt` using SHA-256. If successful, it will output the cracked password in the terminal.

After a while, Hashcat should output:
```
b31f2c047e442f9e88f27ab3742c18d8a305d43ac034c6b0f65fb095260c5a7a:not2secure
```

This means that the password corresponding to the SHA-256 hash is `not2secure`.

### **Step 6: Logging In**
Now, return to the challenge page, enter the credentials:
- **Username**: `admin`
- **Password**: `not2secure`

And voilà! You should be logged in, revealing the flag:
```
Securinets{DAyuM_S0n_WhRe'd_ya_f1Nd_tH1s}
```

## **Conclusion**
This challenge demonstrates the importance of avoiding hardcoded credentials and properly securing sensitive information. By using tools like Hashcat, we can analyze and exploit poorly implemented security measures in web applications.

