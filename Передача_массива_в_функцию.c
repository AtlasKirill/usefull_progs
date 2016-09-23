#include <stdio.h>

int my_strlen(char *str)
{
	int a = 0;
	int i = 0;
	while (str[i] != '\n') {
		a++;
		i++;
	}
	for (i = 0; i<a; i++) {
		str[i]++;
	}
	return a;
}


int main()
{
	int k=0;
	int i = 0;
	char string[] = "Hello\n";
	k=my_strlen(string);
	for (i = 0; i<k; i++) {
		printf("%c", string[i]);
	}
	return 0;
}
