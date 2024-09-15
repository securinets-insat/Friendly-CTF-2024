#include <stdio.h>
#include <signal.h>


void handle_timeout(){
	puts("don't take too long !");
	exit(69);
}

void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	signal(SIGALRM, handle_timeout);
	alarm(5);
}


void main(){
	setup();
	puts("\"https://wpengine.com/builders/quick-tips-wpgraphql-non-ascii-queries/#:~:text=Non%2DASCII%20characters%20are%20characters,and%20cultures%20across%20the%20globe.\"");
	puts("welcome to the gate of INSAT city");
	puts("give my your password shall you enter .");
	puts("It better be a password no one can type with their keyboard");

	puts("");

	char buf[32]={0};

	scanf("%31s", buf);


	if (!strcmp(buf,"\xc8\x65\xff\x16\x42\xf7")){
		puts("i dont see those words , how the hell could you type them .");
		puts("enjoy your flag !!!");
		system("cat flag.txt");
	}
	else {
		printf("i dont like this password %s\n",buf);
	}
	return;

}