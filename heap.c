#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Toystr{
void (*message)(char *);
char buffer[10];
};

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2
static int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;
    // Output prompt then get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL)
        return NO_INPUT;
    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }
    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;
}
void print_cool(char * who)
{
printf("%s is cool!\n", who);
}
void print_meh(char * who)
{
printf("%s is meh...\n", who);
}
int main(int argc, char **argv) {
    
	struct Toystr* coolguy=malloc(sizeof(struct Toystr));
	struct Toystr* lameguy=malloc(sizeof(struct Toystr));
	coolguy->message = &print_cool;
	lameguy->message = &print_meh;
	
	printf("Input coolguy's name: ");
	getLine("",coolguy->buffer,10);
	coolguy->buffer[strcspn(coolguy->buffer,"\n")] =0;

	printf("Input lameguy's name: ");
	getLine("",lameguy->buffer,10);	
	
	lameguy->buffer[strcspn(lameguy->buffer,"\n")] =0;
	coolguy->message(coolguy->buffer);
	lameguy->message(lameguy->buffer);
}
//fgets(lameguy->buffer,10,stdin);
//fgets(coolguy->buffer,10,stdin);// oopz...
