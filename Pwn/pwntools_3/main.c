#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void handle_timeout(){
	puts("you gotta be as quick as Glenn Rhee .");
	exit(69);
}

void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	signal(SIGALRM, handle_timeout);
	alarm(3);
}


void main(){
	setup(); // don't mind this 

	int fd=open("/dev/urandom",1);
	int seed,guess,i;
	int values[0x10];
	int inputs[0x10];
	read(fd,&seed,sizeof(seed));
	srand(seed);
	for (i=0;i<0x10;i++)
		values[i]=rand();
	// just getting some random numbers , dont mind it


	for (i=0;i<0x10;i++)
		printf("%d\n",values[i]);
	
	puts("can you do it in 3 seconds ? i doubt it");

	for (i=0;i<0x10;i++)
		scanf("%d%*n",&inputs[i]);  // asks for 16 integers from input

	
	if (!memcmp(inputs,values,4*0x10)){   // compares the integers you inputted with the random integers 
		alarm(0);
		puts("You're quick with it , i wonder how !!!");
		puts("here's your flag !!!");
		system("cat flag.txt");
	}

	return;
}
