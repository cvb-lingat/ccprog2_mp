#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	AskVaxi is a function that displays the chatbot's responses to the user's questions.
	
	No parameters.
*/
void 
AskVaxi()
{
	FILE *Vaxi; // file pointer
	char Question[81]; // User's question input
	char FileInput[81]; // variable that will retrieve strings from the file
	char Answers[26][81]; // stores the strings from the file
	int flag = 0; // loop evaluation variable
	int counter = 0; // counter variable for loops
	int i; // counter variable for loops
	
	// always assume that Vaxi.txt exists (VERY IMPORTANT)
	Vaxi = fopen("Vaxi.txt", "r");
	
	while (fgets(FileInput, 81, Vaxi) != NULL) // retrieves strings until EOF
	{
		FileInput[(int) strlen(FileInput) - 1] = '\0'; // replaces the \n in every retrieved string with null character
		strcpy(Answers[counter], FileInput); // copies the FileInput into an array of strings
		counter++; // increments for index purposes
	}
	system("cls");
	
	printf("VAXI: Hello! My name is Vaxi and I am at your service! May I know what do you want to ask? You may exit by inputting '0'\n");
	printf("Please know that almost all my answers are from the CDC of the USA and the DOH of the Philippines.\n");
	
	do
	{
		flag = 0;
		
		fflush(stdin);
		printf(">>");
		gets(Question); // gets the user's question (gets because of spaces)
		
		if (strcmp("0", Question) != 0) // executes if user does not input 0
		{
			for (i = 0; i < counter && flag == 0; i++) // loops until i > counter or flag != 0 (question is found)
			{
				if( strcmp(Question, Answers[i]) == 0)
				{
					printf("VAXI: %s\n", Answers[i+1]); // prints the next string (because the following string after a question is the answer for it)
					flag = 1;
				}
			}
			
			if (flag == 0)
				printf("VAXI: Sorry. I do not know the answer. :( Please type another question.\n"); // executes if no such question found)
		}
		
	} while ( strcmp("0", Question) != 0); // terminates loop if user inputs 0
	
	printf("\n\nVAXI: Thank you for coming! Stay safe always!\n");
	system("pause");
	
	fclose(Vaxi); // close file
}

