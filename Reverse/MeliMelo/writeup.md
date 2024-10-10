You can run strings melimelo and it will give you at one point the encrypted flag, you can deduce it from ending with == 
that it's a base 64 encryption. Then just google the decryption.

Or 

You execute the program with gdb, run disass main, you can analyze the assembly and you will see that there's a function named func_0192 after the scanf call: 

   0x000000000000172d <+713>:   call   0x1130 <__isoc99_scanf@plt>
   0x0000000000001732 <+718>:   movzx  eax,BYTE PTR [rbp-0xdd]
   0x0000000000001739 <+725>:   movsx  edx,al
   0x000000000000173c <+728>:   lea    rax,[rbp-0xc0]
   0x0000000000001743 <+735>:   mov    esi,edx
   0x0000000000001745 <+737>:   mov    rdi,rax
   0x0000000000001748 <+740>:   call   0x12cc <func_0192>
   0x000000000000174d <+745>:   mov    DWORD PTR [rbp-0xdc],eax
   0x0000000000001753 <+751>:   add    DWORD PTR [rbp-0xd8],0x1
   0x000000000000175a <+758>:   cmp    DWORD PTR [rbp-0xdc],0x0
   0x0000000000001761 <+765>:   jne    0x1540 <main+220>
   0x0000000000001767 <+771>:   mov    eax,0x0
   0x000000000000176c <+776>:   call   0x144a <nomelimelo>
   0x0000000000001771 <+781>:   mov    eax,0x0
   0x0000000000001776 <+786>:   mov    rdx,QWORD PTR [rbp-0x8]
   0x000000000000177a <+790>:   sub    rdx,QWORD PTR fs:0x28
   0x0000000000001783 <+799>:   je     0x178a <main+806>
 
run disass func_0192 , you get its assembly code : 

   0x0000555555555374 <+168>:   cmp    BYTE PTR [rbp-0x1c],al
   0x0000555555555377 <+171>:   jne    0x555555555380 <func_0192+180>
   0x0000555555555379 <+173>:   mov    DWORD PTR [rbp-0xc],0x1
   0x0000555555555380 <+180>:   mov    eax,DWORD PTR [rbp-0xc]

there's a cmp that compares the char with the input so we are going to put a breakpoint at the jne "break *0x0000555555555377", then run until you hit the breakpoint and run "set {char}0x0000555555555377 = 0x74"
set the char to 0x74 (je) in the instruction of the comparison and you continue executing 5 times
then you have the flag encrypted in base64 printed.