### HashKitty Writeup

When inspecting the code, we notice some changes in how the password is processed. Here's what we found:

- A new variable called `seasoning` was added with the value `"03"`.
- The `seasoning` value is added to the password before it's turned into a hash and checked against the stored hash.

### What is "Seasoning"?

The term "seasoning" in this context is a hint towards **salting**, which is a method used in cryptography. A **salt** is just extra data added to the password before it's hashed, which makes the hash harder to crack. The purpose of using salts is to ensure that even if two users have the same password, their stored hash values will be different, making it more secure.

### Why Can't We Crack it Easily?

In the first HashKitty task, many participants used free online hash-cracking websites to break the hash. But in this task, the use of a **salt** makes it impossible to crack using those websites, since they don’t allow you to include a salt. This challenge pushes you to use **Hashcat**, a powerful offline password-cracking tool used by professionals.

### Cracking the Hash with Hashcat

[**Hashcat**](https://hashcat.net/wiki/doku.php?id=hashcat) is a tool specifically designed for cracking hashes, especially when there’s more complexity involved, like a salt. After reading through its documentation, we found out how to use Hashcat when you know both the hash and the salt. Here’s the command:

```bash
hashcat -m 1410 -a 0 hash.txt /usr/share/wordlists/rockyou.txt
```

Breaking it down:

- `-m 1410`: This tells Hashcat that the hash format is **SHA-256 with a salt**. The number `1410` is the specific code for that type of hash.
- `-a 0`: This sets the attack mode to "straight," meaning Hashcat will try each word from a wordlist against the hash.
- `hash.txt`: This is the file that contains the hash we want to crack (along with the salt). [FILE FORMAT: "HASH:SALT"]
- `/usr/share/wordlists/rockyou.txt`: This is a common wordlist used in cracking, containing many MANY popular passwords (yours just might be one of them...).

### Example Output

After running the command, Hashcat will work its magic and if the password is in the wordlist, you'll see something like this in the output:

```bash
c4a521f815496be53f64ef8e1e3f2ab964dbcf5d94cb21cc965796a44985ebb4:03:h@ppybirthday
```

In this case, **h@ppybirthday** is the correct password! The value `03` is the salt, but you don’t need to add it when entering the password, because the code handles that for you.

### Common Beginner Mistakes

Some participants might think they need to enter the password as `h@ppybirthday03` in the login form. But remember, the PHP code **already** adds the `03` salt to your password behind the scenes. So, just enter **h@ppybirthday** as the password.

### Pro Tip

If you've run the command once and want to check the result later without re-cracking it, you can use the `--show` option in Hashcat to see the cracked password again:

```bash
hashcat -m 1410 --show hash.txt
```

### Conclusion

This task successfully highlights how proper salting helps protect against brute force attacks and should teach you how to properly read documentation and use tools such as hashcat.


# ALTERNATE SOLUTION

Just concatenate 03 to each line in the wordlist rockyou.txt and run hashcat normally on it (for the people that found trouble configuring hashcat to use the salt value)

This is not a recommended solution since it only works for this specific example but if it works it works.