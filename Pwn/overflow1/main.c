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
	for (i=0;i<num;i++){
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

void main(){
	setup(); // dont mind this

	long CHANGE_ME = 0xdeadbeef;
	char buf[16];
	print_stack(buf,3);
	puts("");
	puts("you vs the beef !!!! WHO WINS ?");

	gets(buf); // vulnerable function
	
	print_stack(buf,5);

	if (CHANGE_ME==0xdeadbeef)
		puts("you can't escape the deadbeef ");
	else {
		alarm(0);
		puts("the deadbeef was no match for you after all !!!! take your flag");
		system("/bin/sh");   //if you got here just use the 'cat flag.txt' command
	}
	exit(0);

}