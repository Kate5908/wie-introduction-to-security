#include <stdio.h>

void win(void) {
	puts("WIT{y0u_sh0u1dn’t_be_4b1e_t0_c411_th15}!");
}

int main(void) {
	char name[30]; // collection of 30 characters
	int is_admin = 0; // we want this to be a non-zero value

	puts("Please enter your name: ");
	gets(name);
	
	if (is_admin != 0) { // this means if is_admin is not equal to 0
		win();
	} else {
		// this prints out this string, with %s being replaced with your name
		printf("Hello %s, no flag for you :(", name);
	}
}
