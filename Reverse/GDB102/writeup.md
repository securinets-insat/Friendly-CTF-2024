The program is using 'ptrace' so we have to disable so that we can run it on gdb.

Open the program with gdb. 
Put a breakpoint in the main function then run.
Disassemble main : 

Dump of assembler code for function main:
   0x0000000000001475 <+0>:     endbr64
   0x0000000000001479 <+4>:     push   rbp
   0x000000000000147a <+5>:     mov    rbp,rsp
   0x000000000000147d <+8>:     sub    rsp,0x10
   0x0000000000001481 <+12>:    mov    eax,0x0
   0x0000000000001486 <+17>:    call   0x143e <func_5678>
   0x000000000000148b <+22>:    lea    rax,[rip+0xbfd]        

Disassemble the function func_5678 : 

Dump of assembler code for function func_5678:
   0x000000000000143e <+0>:     endbr64
   0x0000000000001442 <+4>:     push   rbp
   0x0000000000001443 <+5>:     mov    rbp,rsp
   0x0000000000001446 <+8>:     mov    eax,0x0
   0x000000000000144b <+13>:    call   0x1209 <func_0928>
   0x0000000000001450 <+18>:    test   eax,eax
   0x0000000000001452 <+20>:    je     0x1472 <func_5678+52>
   0x0000000000001454 <+22>:    lea    rax,[rip+0xc0d]

Disassemble func_0928 , we notice one line :  call   0x5555555550e0 <ptrace@plt>

So the function func_0928 is responsible for stopping the program if the anti-debugger ptrace detects a debugger.
To bypass it we have to change the output of the ptrace function to 0, so we will put a breakpoint here : 0x0000000000001450 <+18>:    test   eax,eax -> break *0x1450

Then continue executing, then when the breakpoint is reached, we set eax register to 0, 
so we run set $eax=0. We have now bypassed the ptrace. 


Now that we have access to the main function, we disassemble the func_5362 : 

   0x00005555555553f1 <+5>:     mov    rbp,rsp
   0x00005555555553f4 <+8>:     sub    rsp,0x20
   0x00005555555553f8 <+12>:    mov    QWORD PTR [rbp-0x18],rdi
   0x00005555555553fc <+16>:    mov    rax,QWORD PTR [rbp-0x18]
   0x0000555555555400 <+20>:    mov    rdi,rax
   0x0000555555555403 <+23>:    call   0x555555555261 <func_1234>
   0x0000555555555408 <+28>:    mov    DWORD PTR [rbp-0x4],eax
   0x000055555555540b <+31>:    cmp    DWORD PTR [rbp-0x4],0x0
   0x000055555555540f <+35>:    je     0x555555555427 <func_5362+59>
   0x0000555555555411 <+37>:    lea    rax,[rip+0xc0a]        # 0x555555556022
   0x0000555555555418 <+44>:    mov    rdi,rax
   0x000055555555541b <+47>:    mov    eax,0x0
   0x0000555555555420 <+52>:    call   0x5555555550c0 <printf@plt>
   0x0000555555555425 <+57>:    jmp    0x55555555543b <func_5362+79>
   0x0000555555555427 <+59>:    lea    rax,[rip+0xc12]        # 0x555555556040
   0x000055555555542e <+66>:    mov    rdi,rax
   0x0000555555555431 <+69>:    mov    eax,0x0
   0x0000555555555436 <+74>:    call   0x5555555550c0 <printf@plt>

By analyzing we can deduce that the func_1234 is responsible for comparing. Let's analyze it in IDA.

We can deduce that it is doing a caesar encyption by 3 on the string "1wV_g33S3u_Wk4q_B0x_Wk1qn". Just reverse it with a decoder online.