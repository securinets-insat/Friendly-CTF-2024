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
int fd=0;
char flag[0x50];
void win(int arg1,int arg2 ,int arg3){
	if (arg1==0x112233 && arg2==0x445566 && arg3==0x778899){
	puts("GG . Here's your flag");
	fd=open("flag.txt",0);
	read(fd,flag,0x50);
	puts(flag);
	return;
	}
	else{
		puts("you were this close :( ");
	}

}

void vuln(){

	char buf[16];

	puts("you made it through iron and now you're bronze !!!");
	puts("let's see if you make it to silver !!!");

	print_stack(buf,5); // this is to help you , dont mind it
	call_trace(); // this is to help you , dont mind it

	puts("");

	printf("the win function is at %p . you better see it in gdb\n");	
	
	gets(buf);    // vulnerable function
	
	print_stack(buf,5); // this is to help you , dont mind it

}


void main(){
	setup(); // dont mind this
	vuln();
	puts("you belong to iron !");
	exit(0);

}