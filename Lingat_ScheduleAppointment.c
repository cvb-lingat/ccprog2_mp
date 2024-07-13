#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	ScheduleAppointment is a function that stores the user's inputs into the "database" of appointments in the program.
	@param ListOfApp - array of type appointmentInfo that will receive the user's input according to the index.
	@param arrayOfAppID - array of AppIDs to check if user's AppID is valid or not used yet.
	@param numberofApps - index of where to store the values for ListOfApp and arrayOfAppID.
*/
void 
ScheduleAppointment (struct appointmentInfo ListOfApp[], 
					int arrayOfAppID[], 
					int numberofApps)
{
	int i, signal = 0, signal2 = 0, found = 0;
	// i is a counter variable, signal, signal2 and found are all evaluation variables.
	
	system("cls");
	
	printf("Enter your chosen Application ID number (valid as long as it is not taken): ");
	scanf("%d", &ListOfApp[numberofApps].appID); // scan for the appointment ID
	
	for (i = 0; i < SIZE && signal == 0; i++) // terminates if i < SIZE or matching appID is found
	{
		if (arrayOfAppID[i] == ListOfApp[numberofApps].appID) 
			signal = 1;
	}
	
	
	fflush(stdin);
	
	if (signal == 1) // if matching appID is found user has to input again
	{
		do
		{
			found = 0; // resets found to 0 for every loop
			
			printf("Your chosen Application ID number has been taken. Please input again: ");
			scanf("%d", &ListOfApp[numberofApps].appID); // scans for input
			
			for(i = 0; i < SIZE && found == 0; i++) // terminates if i < SIZE or found != 0
			{
				if (ListOfApp[numberofApps].appID == arrayOfAppID[i])
					found = 1;
			}
			
			if (found == 0) // if found is 0 meaning no matching numbers, signal2 is set to 1.
				signal2 = 1; // makes signal2 == 0 false
						
		} while (signal2 == 0); // terminates if signal2 is 1
		
		arrayOfAppID[numberofApps] = ListOfApp[numberofApps].appID; // assigns the of ListOfApp to arrayOfAppID in the same index
	}
	
	else
		arrayOfAppID[numberofApps] = ListOfApp[numberofApps].appID; // assigns the of ListOfApp to arrayOfAppID in the same index
	
	fflush(stdin);
	
	printf("Input your name: ");
	gets(ListOfApp[numberofApps].name); // scans the name (gets because of space)
	
	fflush(stdin);
	
	printf("Input your chosen location of vaccination: ");
	gets(ListOfApp[numberofApps].location); // scans the name (gets because of space)
	
	fflush(stdin);
	
	printf("Input your chosen vaccine: ");
	scanf("%s", ListOfApp[numberofApps].vaccine); // scans the vaccine of choice
	
	fflush(stdin);
	
	printf("Input the chosen date of vaccination (YYYY-MM-DD): ");
	scanf("%s", ListOfApp[numberofApps].date); // scans the date
	
	fflush(stdin);
	
	printf("Input your chosen time of vaccination (24-hour format): ");
	scanf("%s", ListOfApp[numberofApps].time); // scans the time
	
	fflush(stdin);
	
	printf("Input the type of dose (Second or Booster): ");
	scanf("%s", ListOfApp[numberofApps].dose); // scans the dose
	
	fflush(stdin);
	
	system("cls");
	
	printf("Thank you for setting an appointment!\n");
	system("pause");
	
}
