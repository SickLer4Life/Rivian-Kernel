#include "kernel/tty.h"
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"

void kernel_early(void) {
	terminal_initialize();
}

int main(void) {
	char *buff;
	strcpy(&buff[strlen(buff)], "");
	printf("<$> Starting Kernel\n");
    printf("<$> Starting Shell\n");
    printf("Booting into KemieBSD beta.\n");
	printprompt();
	while (1) {
		uint8_t byte;
		while (byte = scan()) {
			if (byte == 0x1c) {
				if (strlen(buff) > 0 && strcmp(buff, "exit") == 0){
					printf("\nGoodbye!");
				}
				else if (strlen(buff) > 0 && strcmp(buff, "clear") == 0){
					printf("\ncleared!");
				}
				else {
					printf("\nKemie command not found");
				}
				printprompt();
				memset(&buff[0], 0, sizeof(buff));
				break;
				
			} else {
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				strcpy(&buff[strlen(buff)], s);
			}
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
	return 0;
}
