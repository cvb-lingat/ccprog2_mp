#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lingat_ManageAppointmentMenu2.c"

/*
	ManageAppointmentMenu is a function that validates the input of the user, meaning it executes its partner program once inputs are valid.
	@param ListOfApp - array of type appointmentInfo to be used for validation purposes and passed to the partner program.
	@param arrayOfAppID - array of appIDs to be used for validation purposes and passed to the partner program.
*/

void 
ManageAppointmentMenu (struct appointmentInfo ListOfApp[], 
						int arrayOfAppID[])
{
	int inputID, i, flag = 0, flag2 = 0, index;
	// inputID is for user's input, flag and flag2 are validation variables, and index is to store the counter of where a data is found
	
	system("cls");
	
	printf("Input your Appointment ID: ");

	scanf("%d", &inputID); // scan for inputID
	
	for (i = 0; i < SIZE && flag == 0; i++) // loops until i < SIZE or flag != 0
	{
		if (arrayOfAppID[i] == inputID) // if appID is found loop terminates and the index gets where it is found
		{
			index = i;
			flag = 1;
		}
	}
	
	if (flag == 1 && inputID > 0) // executes ManageAppointmentMenu2 if input is >0 and flag is set to 1
	{
		ManageAppointmentMenu2(ListOfApp, arrayOfAppID, index);
	}
	
	else // executes if flag is not set to 1
	{
		printf("Your Appointment ID is not found. Please input another or enter '0' if you want to exit.\n");
		
		do
		{
			scanf("%d", &inputID); // scan for inputID
			
			if (inputID > 0) // executes if inputID > 0
			{
				for (i = 0; i < SIZE && flag2 == 0; i++) // loops until i < SIZE or flag2 != 0
				{
					if (arrayOfAppID[i] == inputID)
					{
						index = i; // gets index of where it is found
						flag2 = 1; // terminates the loop
					}
				}
			}
		} while (inputID > 0 && flag2 == 0);
		
		if (flag2 == 1)
			ManageAppointmentMenu2(ListOfApp, arrayOfAppID, index); // if matching ID is found, ManageAppointmentMenu2 executes.
	}
}
