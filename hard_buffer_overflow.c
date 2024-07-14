#include <stdio.h>

void win(void) {
	puts("WIT{Y0u_d3feat3d_0ur_can4ry}!");
}

int main(void) {
	char name[30]; // collection of 30 characters
	int canary = 0xcafebabe;

	printf("The win function is at %p\n", win);

	puts("Please enter your name: ");

	gets(name);
	
	if (canary != 0xcafebabe) { // if canary is not equal to 0xcafebabe
		puts("Nice try hacker!!");
		return 1; // quit the program
	}
	
	// this prints out this string, with %s being replaced with your name
	printf("Hello %s, no flag for you :(", name);
}
