#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
	UserRegistration is a function that stores the user's inputs to the array of user-related information struct.
	@param myInfo - array of type userInfo to store the user's input depending on the number of users
	@param arrayOfUserID - array of userIDs to check if user's inputted User ID is used or not yet.
	@param numOfUsers - integer that will be serve as the index of where to store inputs in myInfo.
*/
void 
UserRegistration (struct userInfo myInfo[], 
						int arrayOfUserID[], 
						int numOfUsers)
{
	// i is counter variable, signal, signal2, and found are all variables for evaluation of conditional statements.
	int i, signal = 0, signal2 = 0, found = 0;
	char YesOrNo;
	// YesOrNo is to help determine if other statements should execute depending on the user's available information
	
	system("cls");
	
	printf("Enter your chosen UserID number (valid as long as it is not taken): ");
	scanf("%d", &myInfo[numOfUsers].userID); // scan for UserID
	
	// loops until signal is 1 or i is greater than SIZE
	for (i = 0; i < SIZE && signal == 0; i++)
	{
		if (arrayOfUserID[i] == myInfo[numOfUsers].userID) // if userID is the same, 1 is assigned to signal
			signal = 1;
	}
	
	
	fflush(stdin);
	
	if (signal == 1) // if signal is 1, user will have to input another UserID until there is no matching UserID.
	{
		do
		{
			found = 0; // if user's userID is still invalid, this resets to 0 every loop
			
			printf("Your chosen UserID has been taken. Please input again: ");
			scanf("%d", &myInfo[numOfUsers].userID); // scan for UserID
			
			// checks if userID inputted matches with any userID in arrayOfUserID
			for(i = 0; i < SIZE && found == 0; i++)
			{
				if (myInfo[numOfUsers].userID == arrayOfUserID[i])
					found = 1; // sets found to 1 if there is a match.
			}
			
			if (found == 0) // if there is no match, signal2 is assigned 1.
				signal2 = 1;
						
		} while (signal2 == 0); // if signal2 is one, then loop stops executing
		
		arrayOfUserID[numOfUsers] = myInfo[numOfUsers].userID; // assigns the arrayOfUserID the value of myInfo[numOfUsers].userID after loop is terminated.
	}
	
	else
		arrayOfUserID[numOfUsers] = myInfo[numOfUsers].userID; // assigns the arrayOfUserID the value of myInfo[numOfUsers].userID if user's input is valid
		
	printf("Enter your chosen password (maximum of 11 characters and no space): ");
	scanf("%s", myInfo[numOfUsers].password); // scan password
	
	fflush(stdin);
	
	printf("Enter your name in this format: First Name Last Name (example - Juan Dela Cruz): ");
	gets(myInfo[numOfUsers].name); // scan name (gets because of spaces)
	
	fflush(stdin);
	
	printf("Enter your address (example - 2401 Taft Avenue, Malate, Manila): ");
	gets(myInfo[numOfUsers].address); // scan address (gets because of spaces)
	
	fflush(stdin);
	
	printf("Enter your contact number: ");
	scanf("%d", &myInfo[numOfUsers].contactNum); // scan contactNum  
	
	fflush(stdin);
	
	printf("Enter your sex (Male or Female): ");
	scanf("%s", myInfo[numOfUsers].sex); // scan Sex
	
	fflush(stdin);
	
	printf("Enter the date of your first dose in this format: YYYY-MM-DD (example - 2023-02-16): ");
	scanf("%s", myInfo[numOfUsers].firstDoseDate); // scan for first dose date

	fflush(stdin);
	
	printf("Enter the name of your first dose vaccine: ");
	scanf("%s", myInfo[numOfUsers].firstDoseVaccine); // scan for first dose vaccine
	
	fflush(stdin);
	
	printf("Enter the city/municipality where you got your first dose: ");
	gets(myInfo[numOfUsers].firstDoseLocation); // scan for first dose location (gets because of spaces)
	
	fflush(stdin);
	
	printf("Did you receive your second dose? [Y]es [N]o: "); // asks user if they have taken 2nd dose
	
	do
	{
		scanf("%c", &YesOrNo);
	} while (YesOrNo != 'Y' && YesOrNo != 'y' && YesOrNo != 'N' && YesOrNo != 'n'); // input validation
	
	if (YesOrNo == 'Y' || YesOrNo == 'y') // executes if user inputs Y or y
	{
		printf("Enter the date of your second dose in this format: YYYY-MM-DD (example - 2023-02-16): ");
		scanf("%s", myInfo[numOfUsers].secondDoseDate); // scans the second dose date
		
		fflush(stdin);
		
		printf("Enter the name of your second dose vaccine: ");
		scanf("%s", myInfo[numOfUsers].secondDoseVaccine); // scans the second dose vaccine
		
		fflush(stdin);
		
		printf("Enter the city/municipality where you got your second dose: ");
		gets(myInfo[numOfUsers].secondDoseLocation); // scans the second dose location (gets because of spaces)
		
		fflush(stdin);
		
		printf("Did you receive your booster dose? [Y]es [N]o: "); // asks user if they have taken booster dose
		
		do
		{
			scanf("%c", &YesOrNo);
		} while (YesOrNo != 'Y' && YesOrNo != 'y' && YesOrNo != 'N' && YesOrNo != 'n'); // input validation
		
		if (YesOrNo == 'Y' || YesOrNo == 'y') // executes if input is Y or y
		{
			printf("Enter the date of your booster dose in this format: YYYY-MM-DD (example - 2023-02-16): ");
			scanf("%s", myInfo[numOfUsers].boosterDoseDate); // scans the booster dose date
		
			fflush(stdin);
		
			printf("Enter the name of your booster dose vaccine: ");
			scanf("%s", myInfo[numOfUsers].boosterDoseVaccine); // scans the booster dose vaccine
			
			fflush(stdin);
			
			printf("Enter the city/municipality where you got your second dose: ");
			gets(myInfo[numOfUsers].boosterDoseLocation); // scans the booster dose location (gets because of spaces)
		}
		
		else // copies "N/A" to Date, Vaccine, and Location if user does not have booster dose
		{
			strcpy(myInfo[numOfUsers].boosterDoseDate, "N/A");
			strcpy(myInfo[numOfUsers].boosterDoseVaccine, "N/A");
			strcpy(myInfo[numOfUsers].boosterDoseLocation, "N/A");
		}
	}
	
	else // copies "N/A to second and booster dose Date, Vaccine and Location.
	{
		strcpy(myInfo[numOfUsers].secondDoseDate, "N/A");
		strcpy(myInfo[numOfUsers].secondDoseVaccine, "N/A");
		strcpy(myInfo[numOfUsers].secondDoseLocation, "N/A");
		strcpy(myInfo[numOfUsers].boosterDoseDate, "N/A");
		strcpy(myInfo[numOfUsers].boosterDoseVaccine, "N/A");
		strcpy(myInfo[numOfUsers].boosterDoseLocation, "N/A");
	}
	
	fflush(stdin);
	
	system("cls");
	printf("Thanks for registering!\n");
	system("pause");

}
