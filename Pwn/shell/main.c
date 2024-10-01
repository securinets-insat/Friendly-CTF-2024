#include <stdio.h>

void main(){
	setbuf(stdout,0);
	setbuf(stdin,0);


	puts("this a shell (terminal) on the server . you can do whatever you want in a shell .");
	puts("read files , write files , execute files ,view/change directories .... ");
	puts("check this cheat sheet for a list of commands 'https://www.geeksforgeeks.org/linux-commands-cheat-sheet/' ");
	puts("find the flag.txt file on the server then print it");


	system("/bin/bash");

}