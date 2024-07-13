#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lingat_AdminMenus.c"
#include "Lingat_ImportExport.c"

/*
	DataManagementMenu is a function where the admin will log in and input the userID and password. Once validated, it will display the options for the admin.
	@param ListOfData - array of type userInfo to be passed to other function.
	@param arrayOfUserID - array of UserIDs to be passed to other functions and validation.
	@param NumOfUsers - pointer variable of the number of users to be passed to other functions for counting purposes.
	@param ListOfApp - array of type appointmentInfo to be passed to other function.
	@param arrayOfAppID - array of AppIDs to be passed to other functions and validation.
	@param numberofApps - pointer variable of the number of appointments to be passed to other functions for counting purposes.
*/
void 
DataManagementMenu(struct userInfo ListOfData[], 
					int arrayOfUserID[], 
					int *NumOfUsers, 
					struct appointmentInfo ListOfApp[], 
					int arrayOfAppID[], 
					int *numberofApps)
{
	char UserID[14] = "AnimoLaSalle!", password[14]; // sets "AnimoLaSalle!" as the UserID and password is for user to input
	int adminID = 1911, IDInput; // sets the adminID to 1911 and IDInput is for user to input
	int i, flag = 0, flag2 = 0, setInput;
	// i is a counter variable, flag and flag2 are both evaluation variables, and setInput is for user's choice after logging in successfully
	
	system("cls");
	
	for (i = 3; i > 0 && flag == 0; i--) // loops until i = 0 or flag != 0
	{
		printf("Enter the UserID (%d Attempts Remaining): ", i); 
		scanf("%d", &IDInput); // scans the admin number / ID
		
		if (IDInput == adminID)
			flag = 1; // if matching, flag is set to one, terminating the loop
	}
	
	if(flag == 1) // executes if flag == 1
	{
		flag = 0; // sets flag back to 0
		
		for (i = 3; i > 0 && flag == 0; i--) // loops until i = 0 or flag != 0
		{
			printf("Enter the password: (%d Attempts Remaining): ", i); 
			scanf("%s", password);
			
			if (strcmp(password, UserID) == 0)
				flag = 1; // if matching, flag is set to one, terminating the loop
				
		}
	}
	
	if (flag == 1) // executes if flag == 1
	{
		
		do
		{
			system("cls");
			
			printf("Data Management Menu\n\n");
			printf("Which settings do you want to access?\n");
			printf("[1] - User Settings\n");
			printf("[2] - Appointment Settings\n");
			printf("[3] - Chatbot Settings\n");
			printf("[4] - Export Data\n");
			printf("[5] - Import Data\n");
			printf("[6] - Exit\n");
			
			do
			{
				scanf("%d", &setInput); // scans for input
			} while (setInput != 1 && setInput != 2 && setInput != 3 && setInput != 4 && setInput != 5 && setInput != 6); // input validation
			
			switch(setInput)
			{
				case 1:
					AdminUserMenu(ListOfData, arrayOfUserID, NumOfUsers); // executes AdminUserMenu if input is 1
					break;
					
				case 2:
					AdminAppointmentMenu(ListOfApp, arrayOfAppID, numberofApps); // executes AdminAppointmentMenu if input is 2
					break;
					
				case 3:
					AdminChatbotSettings(); // executes AdminChatbotSettings if input is 3
					break;
					
				case 4:
					ExportAllData(ListOfData, *NumOfUsers, ListOfApp, *numberofApps);  // executes ExportAllData if input is 4
					break;
					
				case 5:
					ImportData(ListOfData, arrayOfUserID, NumOfUsers, ListOfApp, arrayOfAppID, numberofApps); // executes ImportData if input is 5
					break;
					
				case 6:
					flag2 = 1; // terminates loop if input is 6 by making flag2 != 0
			}
			
		} while (flag2 == 0);
	}
	
}
