/* program to copy a content of a file to other file*/
#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{ 
        // Declaration of file pointer's
	FILE *fp1, *fp2;
	char filename[100],c;

        // opening a source file
	fp1 = fopen(argv[1], "r");
	
	// condition to check whether the file is opened or not
	if (fp1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}
        
        // creating an destination file
	fp2 = fopen(argv[2], "w");
	// condition to check whether the file is created or not
	if (fp2 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

        // getting a copy
	c = fgetc(fp1);
	
	// condition to copy a content 
	while (c != EOF)
	{
		fputc(c, fp2);
		c = fgetc(fp1);
	}

	printf("Successfully copied into %s\n", argv[2]);

	fclose(fp1);
	fclose(fp2);
	return 0;
}

