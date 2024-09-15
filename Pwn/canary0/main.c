#include <stdio.h>



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
int fd=0;
char flag[0x50];
void win(){
	puts("GG . Here's your flag");
	puts("");
	fd=open("flag.txt",0);
	read(fd,flag,0x50);
	puts(flag);
	return;
	
}

void vuln(){

	long dont_change_me=0xdeadb0d7;
	char buf[16];

	puts("you reached gold elo after abusing some buffer overflows .");
	puts("you know there is a counterplay for that right ?");

	print_stack(buf,5); // this is to help you , dont mind it
	call_trace(); // this is to help you , dont mind it
	
	gets(buf) ;   // vulnerable function
	
	if (dont_change_me!=0xdeadb0d7) exit(-1);   // if exit is is called , the program will finish without returning to saved return address you used to overwrite xD 
	
	print_stack(buf,5); // this is to help you , dont mind it
	
	return;
}


void main(){
	setup(); // dont mind this
	vuln();
	puts("you're stuck");
	exit(0);

}