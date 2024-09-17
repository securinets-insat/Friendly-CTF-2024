s = [''] * 25  # Initialize a list with 25 empty strings
s[0] = 'S'
s[1] = 'e'
s[2] = 'c'
s[3] = 'u'
s[4] = 'r'
s[5] = 'i'
s[6] = 'n'
s[7] = 'e'
s[8] = 't'
s[9] = 's'
s[10] = '{'
s[11] = 'H'
s[12] = '4'
s[13] = 'c'
s[14] = 'k'
s[15] = '3'
s[16] = 'r'
s[17] = 's'
s[18] = '_'
s[19] = 'W'
s[20] = chr(ord(s[15]) - 3)  # Calculate character for s[20]
s[22] = chr(ord(s[20]) + 60)  # Calculate character for s[22]
s[23] = chr(148 - ord(s[20])) # Calculate character for s[23]
s[21] = chr(30 ^ ord(s[22]))  # Calculate character for s[21]
s[24] = chr(15 ^ ord(s[21]))  # Calculate character for s[24]

# Join the list to get the final string
result = ''.join(s)
print(result)
