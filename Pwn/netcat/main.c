#include <stdio.h>

void main(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stdout,0);

	system("cat banner");

	puts("");
	puts("");
	puts("");
	puts("");

	system("cat flag.txt");



}