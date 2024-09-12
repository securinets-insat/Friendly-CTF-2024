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
}

void call_trace(){
	puts("");
	long * ptr;
	ptr=*(&ptr+1);
	printf("the vuln function was called by main in %p .\n",(long)*(ptr+1)-5);
	printf("After vuln continues execution , it returns to main and exactly to %p .\n",(long)*(ptr+1));
	printf("But how does vuln know where to return ? the answer lies in the stack . \n");
	printf("And could you possibly interfere with it and make it return somewhere else ? maybe somewhere where you get the flag\n");
	puts("");
	return;
}

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
	char flag[0x50];
	int fd=open("flag.txt",0);
	read(fd,flag,0x50);
	puts(flag);
	return;
}

void vuln(){

	char buf[16];


	print_stack(buf,5); // this is to help you , dont mind it
	call_trace(); // this is to help you , dont mind it
	puts("welcome to the league of winners . you start at iron . let's see if you make it through . ");
	puts("");

	printf("the win function is at %p . try to execute it somehow\n",&win);	

	gets(buf);    // vulnerable function
	
	print_stack(buf,5); // this is to help you , dont mind it

}


void main(){
	setup(); // dont mind this
	vuln();
	puts("maybe you should stick to master yi !");
	exit(0);

}