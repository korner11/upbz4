#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  BUFF 128

//1234567890123456j?*!
//j = 0x6A, ? = 0x10, * = 0x2A, and ! = 0x21
bool IsPasswordOK(void) {
   char Password[12];

   fgets(Password, BUFF, stdin);
   return 0 == strcmp(Password, "goodpass\n");

}

void func1() {

	bool PwStatus;
	
	puts("Enter password:");
	PwStatus = IsPasswordOK();
	if (!PwStatus) {
			puts("Access denied");
	}
	else {
		puts("Access granted");
	}
}
int copy(char *dst, char *src, unsigned int len)
{
	
	// negative value is converted to unsigned int random number
	while (len--)
		*dst++ = *src++;

	return len;
}

void func2() {

	printf("\nThis is func2");
	char str1[5];
	char str2[5];
	printf("\nEnter string\n");
	fgets(str1, BUFF, stdin);
	int f = -1;//if(f<0) f=0;
	int smt = copy(str2, str1, f);
	printf("\n %d big number ", smt);


}

void func3() {

	printf("\nThis is func3");

}



int main(int argc, char* argv[]) {
	
	if (argc == 0)
	{
		printf("Please specify arguments!");
	}
	else
	{

		/*for (int i = 0; i < argc; i++) {
			printf("%s\n", argv[1]);
		}*/
		char *endptr;
		long int x = strtol(argv[1], &endptr, 10);
		switch (x) {
		case 1: func1(); break;
		case 2: func2(); break;
		case 3: func3(); break;
		default: printf("Bad arguments!"); break;
		}
	}
}