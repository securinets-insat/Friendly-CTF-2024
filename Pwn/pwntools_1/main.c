#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void handle_timeout(){
	puts("");
	puts("too slow !!! you gotta be as quick as Glenn Rhee .");
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
	setup(); // don't mind this 
	char buf[32]={0};

	puts("use pwntools to establish remote connection . https://docs.pwntools.com/en/stable/intro.html");
	puts("send me your favorite movie");
	scanf("%31s",buf);
	if (buf[0]){    // checks if there is at least 1 character typed
		puts("GG");
		puts("enjoy your flag");
		system("cat flag.txt");
	}

	return;
}