#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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



void safeStrncpy(char **p_buffer, size_t *p_bufsiz, const char *src)
{
    size_t newlen = strlen(src) + 1;
    if (*p_bufsiz < newlen)
    {
        char *n_buffer = malloc(newlen);
        if (n_buffer == 0)
        {
            fprintf(stderr, "Failed to allocate %zu bytes memory\n", newlen);
            return;
        }
        *p_buffer = n_buffer;
        *p_bufsiz = newlen;
    }
    memmove(*p_buffer, src, newlen);
}
int main(int argc, char** argv)
{
		char *meno = 0;
		size_t bufsiz = 5;
		char *heslo = 0;
		size_t bufsiz1 = 5;		
		char line[10];

		fgets(line,5,stdin);		
//getLine("Zadajte meno: ",line,5);
		safeStrncpy(&meno, &bufsiz, line);
			
		//getLine("Zadajte heslo: ",line,5);
		safeStrncpy(&heslo, &bufsiz1, line);
		printf("Meno: %s\n", meno);
		printf("Heslo: %s\n", heslo);
		free(meno);
		free(heslo);

}
