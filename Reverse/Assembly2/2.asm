MOV eax, 0x58
XOR ebx, ebx
MOV ebx, eax
XOR eax, 0xF0
SHR eax, 1
XOR eax, eax
XOR eax, ebx
XOR eax, 0x16

MOV eax, 0x4F
XOR eax, 0x10
ADD eax, 0x51
XOR eax, 0x10
NOT eax
XOR eax, 0x1E

MOV eax, 0x52 
XOR eax, 0xA 
ADD eax, 0x6 
XOR eax, 0xA 
SUB eax, 0xC

MOV eax, 0x69
OR eax, 0x2 
XOR eax, 0x4A 
AND eax, 0xFB 
XOR esp, esp 
XOR esp, eax
XOR esp, 0x7C
XOR eax, eax
XOR eax, esp

MOV eax, 0x6E
XOR esp, esp
XOR esp, eax
XOR eax, 0xF0
SHL eax, 3
AND esp, 0x42
XOR eax, eax
XOR eax, esp

MOV eax, 0x67
ROL eax, 1   
XOR eax, 0x6D 
ROR eax, 1    
SUB eax, 0x68
ADD eax, 0x9

MOV eax, 0x5F
NOT eax    
ADD eax, 0xB0 
SUB eax, 0xF0
XOR eax, 0x1F 
MOV edx, 0x3F
XOR eax, edx
XOR edx, edx

