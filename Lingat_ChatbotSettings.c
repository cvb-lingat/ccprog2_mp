#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Allows user to view contents of a text file.
	No parameters.
*/
void
ViewAllQA ()
{
	FILE *Vaxi; // file pointer
	char strQA[26][81]; // array of strings to store the contents of the file
	char strFileInput[81]; // retrieves the file
	int dCounter = 0, i; // counter variables
	
	system("cls");
	
	Vaxi = fopen("Vaxi.txt", "r"); // opens the file (assuming it exists)
	
	while ( fgets(strFileInput, 81, Vaxi) != NULL ) // assigns the strings into strQA and increments dCounter until EOF
	{
		strFileInput[ (int) strlen(strFileInput) - 1] = '\0';
		strcpy(strQA[dCounter], strFileInput);
		dCounter++;
	}
	
	for (i = 0; i < dCounter; i++) // prints the contents of strQA
	{
		printf("%s\n", strQA[i]);
	}
	
	fclose(Vaxi); // closes the file
	
	printf("\n");
	system("pause");
}

/*
	AddNewQA allows the user to add questions and answers
	
	No parameters.
*/
void 
AddNewQA()
{
	FILE *Vaxi; // file pointer
	char strQA[26][81]; // array of strings to store the contents of the file
	char strFileInput[81]; // retrieves the file contents
	char userInput[81]; // question input
	char userInput2[81]; // question output
	int dCounter = 0, i; // counter variables
	
	system("cls");
	
	// assume that Vaxi.txt always exists
	Vaxi = fopen("Vaxi.txt", "a+");
	
	while ( fgets(strFileInput, 81, Vaxi) != NULL ) // assigns the strings into strQA and increments dCounter until EOF
	{
		strFileInput[ (int) strlen(strFileInput) - 1] = '\0';
		strcpy(strQA[dCounter], strFileInput);
		dCounter++;
	}
	
	for (i = 0; i < dCounter; i++) // prints the contents of strQA
	{
		printf("[%d] - %s\n", i, strQA[i]);
	}
	
	printf("\nHere are the QAs in the text file.\n");
	printf("What question do you want to add?\n");
	
	fflush(stdin);
	
	gets(userInput); // gets the Question
	
	fprintf(Vaxi, "%s\n", userInput);
	
	fflush(stdin); 
	
	printf("What answer for that question do you want to add?\n");
	
	gets(userInput2); // Gets the Answer
	
	fprintf(Vaxi, "%s\n", userInput2); // prints contents back into the file
	
	fflush(stdin);
	
	fclose(Vaxi); // closes the file
}
/*
	EditQA allows users to edit any question or answer in the file.
*/
void 
EditQA()
{
	FILE *Vaxi; // file pointer
	char strQA[26][81]; // array of strings to store the contents of the file
	char strFileInput[81]; // retrieves the file contents
	char userInput[81]; // the new edit
	int dCounter = 0, i, dString; // counter variables
	
	Vaxi = fopen("Vaxi.txt", "r+"); // opens the file in read and write mode
	
	while ( fgets(strFileInput, 81, Vaxi) != NULL) // assigns the strings into strQA and increments dCounter until EOF
	{
		strFileInput[ (int) strlen(strFileInput) - 1] = '\0';
		strcpy(strQA[dCounter], strFileInput);
		dCounter++;
	}
	
	system("cls");
	
	for (i = 0; i < dCounter; i++)
	{
		printf("[%d] - %s\n", i, strQA[i]); // displays contents of strQA
	}
	
	printf("Which string do you want to edit?\n");
	
	scanf("%d", &dString); // asks which string to edit
	
	fflush(stdin);
	
	printf("Input your edit:\n");
	gets(userInput); // gets the edit for that string
	
	strcpy(strQA[dString], userInput); // copies the string into the strQA and its respective index
	
	fseek(Vaxi, 0, SEEK_SET); // sets the stream back to the top
	
	for (i = 0; i < dCounter; i++)
	{
		fprintf(Vaxi, "%s\n", strQA[i]); // prints the contents back into the file
	}
	
	fclose(Vaxi);
	
}

/*
	DeleteQA allows user to delete a file
	
	No parameters
*/	
void 
DeleteQA()
{
	FILE *Vaxi; // file pointer
	char strQA[24][81]; // array of strings to store the contents of the file
	char strFileInput[81]; // retrieves the file contents
	int dCounter = 0, i, dString; // counter variables
	
	Vaxi = fopen("Vaxi.txt", "r+"); // opens the file in read and write mode
	
	while ( fgets(strFileInput, 81, Vaxi) != NULL)  // assigns the strings into strQA and increments dCounter until EOF
	{
		strFileInput[ (int) strlen(strFileInput) - 1] = '\0';
		strcpy(strQA[dCounter], strFileInput);
		dCounter++;
	}
	
	system("cls");
	
	for (i = 0; i < dCounter; i++) // displays the contents of strQA
	{
		printf("[%d] - %s\n", i, strQA[i]);
	}
	
	printf("Which string do you want to delete? Input -1 if you want to exit.\n");
	scanf("%d", &dString);
	
	if (dString != -1) // executes if string is not -1
	{
		strcpy(strQA[dString], "-1"); // indicates that string should be overwritten
		
		fseek(Vaxi, 0, SEEK_SET); // restarts the stream
		
		for (i = 0; i < dCounter; i++)
		{
			if (strcmp(strQA[i],"-1") != 0)
			{
				fprintf(Vaxi, "%s\n", strQA[i]); // prints the contents of strQA back to the file as long as it is not -1
			}
		}
		
	}
	fclose(Vaxi); // closes the file
	
	system("pause");
	
}
