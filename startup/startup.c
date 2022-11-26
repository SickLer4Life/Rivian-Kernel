#include "../kernel/tty.h"
#include "../kernel/io.h"
#include "../kernel/kbd.h"
#include "../libc/include/string.h"

void startup_feedback(void){
    printf("<$> Starting Kernel\n");
    printf("<$> Starting Shell\n");
    printf("Booting into KemieBSD beta.\n");
}
