#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

char message[] = "Bad input";

int main()
{
	char string[30];
	char *found;
	
	while (1) {
		fgets(string, 30, stdin);
		string[strlen(string) - 1] = '\0';

		found = strtok(string,"(");

		if (found==NULL) return 1;

		for(int i = 0; found[i]; i++) found[i] = tolower(found[i]);

		if (strcmp(found, "circle") == 0) {
			int count = 0;
			float x, y, r;

			while(found && count < 2) {
        		found = strtok(NULL, " ");
				printf("%s\n", found);
				if (found==NULL) {
					puts(message);
					return 1;
				}
				if (count == 0) x = atof(found);
				else if (count == 1) y = atof(found);
				count++;
    		}

        	found = strtok(NULL, ")");
			if (found==NULL) {
				puts(message);
				return 1;
			}
			
			r = atof(found);

			printf("%f %f %f\n", x, y, r);
			
		}





	}

    return 0;
}
