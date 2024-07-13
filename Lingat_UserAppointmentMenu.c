#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lingat_ScheduleAppointment.c"
#include "Lingat_ManageAppointmentMenu.c"

/*
	UserAppointmentMenu is a function that displays to the user what are their options related to appointments.
	@param ListOfApp - array of type appointmentInfo to be passed to other functions.
	@param arrayOfAppID - array of AppIDs to be passed to other functions for checking purposes.
	@param numberofApps - pointer variable to increment the total number of appointments for every appointment scheduled.
*/

void 
UserAppointmentMenu (struct appointmentInfo ListOfApp[], 
							int arrayOfAppID[], 
							int *numberofApps)
{
	int AppMenuChoice, flag = 0;
	// AppMenuChoice is the user's input
	// flag is for loop evaluation
	
	do
	{
		system("cls");
		
		printf("Vaccination Appointment Menu\n\n");
		printf("What would you like to do?\n");
		printf("[1] - Schedule an Appointment\n");
		printf("[2] - View My Appointment\n");
		printf("[3] - Quit\n");
		
		do
		{
			scanf("%d", &AppMenuChoice);
		} while (AppMenuChoice != 1 && AppMenuChoice != 2 && AppMenuChoice != 3); // input validation
		
		switch (AppMenuChoice)
		{
			case 1:
				ScheduleAppointment(ListOfApp, arrayOfAppID, *numberofApps); // executes ScheduleAppointment if user inputs 1
				*numberofApps+=1; // increments the total number of appointments by 1
				break;
			
			case 2:
				ManageAppointmentMenu(ListOfApp, arrayOfAppID); // executes ManageAppointmentMenu if user inputs 2
				break;
			
			case 3:
				flag = 1; // if user inputs 3, if makes flag == 0 false, terminating the loop.
		}
		
	} while (flag == 0);
}
