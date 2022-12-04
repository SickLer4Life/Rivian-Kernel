#include "kernel/tty.h"
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"
#include "stdint.h"
#include "stddef.h"
#include "stdarg.h"
#include "kernel/tty.h"

void kernel_early(void) {
	terminal_initialize();
}

int main(void) {
	char *buff;
	strcpy(&buff[strlen(buff)], "");
	printf("Welcome To The AmianOS Terminal Emulator\n");
	printf("\n");
	
	printprompt();
	while (1) {
		uint8_t byte;
		while (byte = scan()) {
			if (byte == 0x1c) {
				if (strlen(buff) > 0 && strcmp(buff, "exit") == 0){
					printf("\nGoodbye!");
				}
				else if (strlen(buff) > 0 && strcmp(buff, "clear") == 0){
					int clear_buff = 1;
					while(clear_buff < 100){
						printf("\n");
						clear_buff ++;
					}
				}
				else if (strlen(buff) > 0 && strcmp(buff, "clr -r") == 0){
					
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
