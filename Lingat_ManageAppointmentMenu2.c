#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	ManageAppointmentMenu2 is a function that allows the user to view and edit the appointment details.
	@param ListOfApp - array of type appointmentInfo for display and to receive new edits.
	@param arrayOfAppID - array of AppIDs to receive the new userID value of -1 if user cancels appointment.
	@param index - the index of where the relevant data is found.
*/
void 
ManageAppointmentMenu2(struct appointmentInfo ListOfApp[], 
						int arrayOfAppID[], 
						int index)
{
	
	int userInput; // user's input
	char YesOrNo; // for user's confirmation purposes if user wants to cancel
	
	system("cls");

	printf("Your current appointment data:\n");
	printf("Appointment ID: %d\n", ListOfApp[index].appID);
	printf("Name: %s\n", ListOfApp[index].name);
	printf("Location: %s\n", ListOfApp[index].location);
	printf("Vaccine: %s\n", ListOfApp[index].vaccine);
	printf("Date: %s\n", ListOfApp[index].date);
	printf("Time: %s\n", ListOfApp[index].time);
	printf("Dose: %s\n\n", ListOfApp[index].dose);
	
	printf("What would you like to do?\n");
	printf("[1] - Reschedule the Date\n");
	printf("[2] - Change the Time\n");
	printf("[3] - Change the Vaccination Location\n");
	printf("[4] - Change the Vaccination Brand\n");
	printf("[5] - Cancel the Appointment\n");
	printf("[6] - Exit\n");
	
	do
	{
		scanf("%d", &userInput);
	} while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6); // input validation
	
	if (userInput == 1)
	{
		printf("Input a new date in this format (YYYY-MM-DD): ");
		scanf("%s", ListOfApp[index].date); // scans the new date
	}
	
	else if (userInput == 2)
	{
		printf("Input a new time in the 24-hour format: ");
		scanf("%s", ListOfApp[index].time); // scans the new time
	}
	
	else if (userInput == 3)
	{
		printf("Input a new location: ");
		scanf("%s", ListOfApp[index].location);	// scans the new location
	}
	
	else if (userInput == 4)
	{
		printf("Input a new vaccine brand: ");
		scanf("%s", ListOfApp[index].vaccine); // scans the new vaccine
	}
	
	else if (userInput == 5)
	{
		printf("Are you sure?\n[Y]es [N]o\n"); // prompts user if they're sure
		
		do
		{
			scanf("%c", &YesOrNo);
		} while (YesOrNo != 'Y' && YesOrNo != 'y' && YesOrNo != 'N' && YesOrNo != 'n'); // input validation
		
		if (YesOrNo == 'Y' || YesOrNo == 'y')
		{
			arrayOfAppID[index] = -1; // sets appID to -1
			ListOfApp[index].appID = -1; // sets appID to -1
			strcpy(ListOfApp[index].name, "CANCEL"); // to show that the appointment is cancelled.
			strcpy(ListOfApp[index].location, "CANCEL");
			strcpy(ListOfApp[index].vaccine, "CANCEL");
			strcpy(ListOfApp[index].date, "CANCEL");
			strcpy(ListOfApp[index].time, "CANCEL");
			strcpy(ListOfApp[index].dose, "CANCEL");
		}
	}
	
}
