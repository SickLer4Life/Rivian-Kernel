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
	printf("               ,        ,\n");
	printf("              /(        )`\n");
	printf("              | \___   /| \n");
	printf("              /- _  `-/  '\n");
	printf("             (/\/ \ \   /\ \n");
	printf("             / /   | `    \ \n");
	printf("             O O   ) /    |\n");
	printf("             `-^--'`&lt;  '\n");
	printf("            (_.)  _  )   / \n");
	printf("             `.___/`    / \n");
	printf("               `-----' / \n");
	printf("  &lt;----.     __ / __   \ \n");
	printf("  &lt;----|====O)))==) \) /====\n");
	printf("  &lt;----'    `--' `.__,' \ \n");
	printf("               |        | \n");
	printf("                \       / \n");
	printf("           ______( (_  / \ \n");
	printf("  (FK)   ,'  ,-----'   |    \n");
	printf("         `--{__________)          \n");
	
	printf("\n");
	printf("\n");
	printf("Kemie Terminal Emulator\n");
	
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
