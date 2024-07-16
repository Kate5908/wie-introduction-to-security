#include <stdio.h>

int main(void) {
        char *flag = "WIT{th3_0dds_w3re_st4ck3d_aga1nst_us}";
        char message[30];

        puts("Please enter a message to be printed: ");
        fgets(message, 30, stdin);

        printf(message);
}