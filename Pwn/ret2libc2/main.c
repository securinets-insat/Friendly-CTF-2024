#include <stdio.h>


// onegadget


void print_stack(long * ptr , int num){
	puts("");
	int i=0;
	printf("\033[1;31m%-20s   %-20s   %-20s\n","addresses","value1","value2");
	for (;i<num;i++){
		printf("\033[1;32m0x%018llx \033[1;37m| 0x%018llx | 0x%018llx >> ",ptr+(i*2),*(ptr+(i*2)),*(ptr+(i*2)+1));	
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
void gadgets(){
	__asm__ __volatile(
			"pop rdi;"
			"ret;"
		);

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


char bin_sh[]="/bin/sh";

void vuln(){

	char buf[24];

	puts("diamond is known to be the true ELO HELL ! can you ");
	puts("btw that secret gadget i gave you earlier , forget it .");
	puts("note : read this 'https://akshit-singhal.medium.com/rop-chain-exploit-with-example-7e444939a2ec'");
	puts("take from it what you need (menghir matsob kol chay)");
	puts("if youre sure it should work but it isnt , try adding a ret before calling system");
	puts("");

	printf("use this for now . address of puts in libc : %p\n",&puts);

	puts("");

	puts("get em ");
	puts("");
	
	gets(buf);

	return ;
}


void main(){
	setup(); // dont mind this
	vuln();
	puts("you're stuck");
	exit(0);

}