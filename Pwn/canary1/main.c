#include <stdio.h>



void print_stack(long * ptr , int num){
	puts("");
	int i=0;
	printf("\033[1;31m%-20s   %-20s   %-20s\n","addresses","value1","value2");
	for (;i<num;i++){
		printf("\033[1;32m0x%016llx \033[1;37m| 0x%016llx | 0x%016llx >> ",ptr+(i*2),*(ptr+(i*2)),*(ptr+(i*2)+1));	
		int j=0;
		char * ptr_str=ptr+i*2;
		for (;j<0x10;j++){
			if (ptr_str[0x10*i+j]>0x20 && ptr_str[0x10*i+j]<0x7f) {
				printf("%c",ptr_str[0x10*i+j]);
			}
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\033[1;37m");
	puts("");
}

void call_trace(){
	puts("");
	long * ptr;
	ptr=*(&ptr+1);
	printf("the vuln function was called by main in %p .\n",(long)*(ptr+1)-5);
	printf("After vuln continues execution , it returns to main and exactly to %p .\n",(long)*(ptr+1));
	return;
}  // hope you dont need this anymore

void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// your challenge starts here , dont mind the above

void win(){
	puts("GG . Here's your flag");
	puts("");
	char flag[0x100]={0};
	int fd=open("flag.txt",0);
	read(fd,flag,0x100);
	puts(flag);
	return;
	
}

void vuln(){

	char buf[16];

	puts("there is a secret ingredient i've added , no way you go above platinum right?");
	puts("first tell me which champion you mained .");
	
	read(0,buf,0x100);   // read is a not null terminated function and doesnt require newline for input end, which means you can use p.send() instead of p.sendline() . EXAMPLE: p.send("aaaaa") will send aaaaa without the \n or the \0 (null byte) and it will be processed
	
	print_stack(buf,5);

	printf("so you're saying you mained %s . disgusting!",buf);   // make use of this to print something important

	gets(buf);
	
	print_stack(buf,5); // this is to help you , dont mind it
	
	return;
}


void main(){
	setup(); // dont mind this
	vuln();
	puts("you're stuck");
	exit(0);

}