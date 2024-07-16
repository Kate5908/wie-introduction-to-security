#include <stdio.h>

void win(void) {
	puts("WIT{1mp0ss1b1e}!");
}

int main(void) {
	char name[30]; // collection of 30 characters

	printf("The win function is at %p\n", win);

	puts("Please enter your name: ");
	gets(name);
	
	// this prints out this string, with %s being replaced with your name
	printf("Hello %s, no flag for you :(", name);
}
