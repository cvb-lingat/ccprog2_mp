#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	AppointmentSecurityCheck returns 1 if user inputs correct userID and password. 0 if otherwise.
	@param arrayOfUserID - array of userIDs to be checked if inputted UserID exists.
	@param ListOfData - array of type userInfo for password validation.
*/
int 
AppointmentSecurityCheck(int arrayOfUserID[], 
						struct userInfo ListOfData[])
{
	// i and j are counter variables, flag and flag1 are evaluation variables, userID is for user's UserID input, and index is to get the index of arrayOfUserID for password purposes.
	int i, j, flag = 0, flag1 = 0, userID, index;
	// password is for user's password input;
	char password[11];
	
	system("cls");
	
	printf("Security Check\n\n");
	
	for (i = 3; i > 0 && flag == 0; i--) // starts at 3 and decrements to show user how many attempts left
	{
		printf("Input your userID (%d Attempts Left): ", i);
		scanf("%d", &userID); // userID input
		
		if (userID > 0) // input cannot be 0 since all elements in arrayOfUserID are initialized to 0 at the start
		{
		
			for (j = 0; j < SIZE && flag == 0; j++) // evaluation purposes
			{
				if (arrayOfUserID[j] == userID) // if userID is found, index receives j and flag is 1, terminating the loop
				{
					index = j;
					flag = 1;
				}
			}
		}
	}
	
	if (flag == 1) // executes if flag is 1
	{
		for (i = 3; i > 0 && flag1 == 0; i--) // starts at 3 and decrements to show user how many attempts left
		{
			printf("Enter your password: (%d Attempts Left): ", i);
			scanf("%s", password); // password input
			
			if ( strcmp(password, ListOfData[index].password) == 0 ) // if password matches, flag1 is set to 1, terminating the loop
			{
				flag1 = 1;
			}
		}
	}
	
	if (flag == 0) // returns 0 if user fails to provide an existing userID
		return 0;
	else if (flag1 == 0) // returns 0 if user fails to provide the correct password
		return 0;
	else // returns 1 if user provides correct inputs
		return 1;
}
