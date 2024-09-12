#include <stdio.h>
#include <signal.h>

void handle_timeout(){
	puts("you gotta be as quick as Glenn Rhee .");
	exit(69);
}

void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	signal(SIGALRM, handle_timeout);
	alarm(10);
}


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

///////////////////////////////////////////////////////////////////////
//the challenge starts here , dont mind the above

int check_loan(int a,int b,int c,int d,int e){

	if (a+b+c+d+e ==0x69) return 1;
	else
		return 0;

}
void main(){
	setup();
	int b,c,d,e;
	b=184759;
	c=2006;
	d=56324;
	e=0xfc54784;
	char comment[16];
	int account_balance;
	print_stack(comment,3);
	puts("\ngive me your bank account balance .");
	scanf("%d%*c",&account_balance);   // reads a number from input
	if (account_balance<0){
		puts("youre too broke , you wont get the loan !!");
		exit(-1);
	}
	puts("\nlets see if we can give you the loan , meanwhile you can tell us what you're doing with the money ?");
	gets(comment);    // zidha ya rabi zidha 
	
	print_stack(comment,7);

	if (check_loan(account_balance,b,c,d,e)){
		puts("");
		puts("our predictions is that you wont be able to pay back the loan . GTFO");
	}
	else {
		puts("");
		puts("you may be broke , but you're devious . you deserve the loan !!!");
		puts("enjoy your shell !!!");
		system("/bin/sh");   
	}
	exit(0);

}