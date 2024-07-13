#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lingat_UserRegistration.c"
#include "Lingat_AppointmentSecurityCheck.c"
#include "Lingat_UserAppointmentMenu.c"
#include "Lingat_ChatbotUsers.c"


/*
	VaccinationRegistrationMenu is a void function that displays the user's options in the Vaccination Registration Menu.
	@param ListOfData - array of type userInfo to pass to other functions to get its contents.
	@param arrayOfUserID - array of userID to be passed for checking purposes.
	@param NumOfUsers - pointer variable to be incremented everytime a registration happens
	@param ListOfApp - array of type appointmentInfo to pass to other functions to get its contents.
	@param arrayOfAppID - array of appID to be passed for checking purposes.
	@param numberofApps - pointer variable to be incremented everytime an appointment is set happens.

*/
void 
VaccinationRegistrationMenu (struct userInfo ListOfData[], 
							int arrayOfUserID[], 
							int *NumOfUsers, 
							struct appointmentInfo ListOfApp[], 
							int arrayOfAppID[], 
							int *numberofApps)
{
	int RegMenuSignal = 0, RegMenuChoice, SecurityFlag;
	// RegMenuSignal is a variable for loops to evaluate.
	// RegMenuChoice is the user's input for other functions to execute.
	// SecurityFlag is for evaluation if UserAppointmentMenu execute depending on the return value of AppointmentSecurityCheck
	
	do
	{
		system("cls");
		
		printf("Welcome to the Vaccination Registration Menu!\n\n");
		printf("What would you like to do?\n");
		printf("[1] - Register My Information\n");
		printf("[2] - Schedule an Appointment\n");
		printf("[3] - Ask Questions to Vaxi\n");
		printf("[4] - Exit\n");
		
		// input validation.
		do
		{
			scanf("%d", &RegMenuChoice);
		} while (RegMenuChoice != 1 && RegMenuChoice != 2 && RegMenuChoice != 3 && RegMenuChoice != 4);
		
		switch (RegMenuChoice)
		{
			case 1:
				UserRegistration(ListOfData, arrayOfUserID, *NumOfUsers); // executes if user inputs 1
				*NumOfUsers+=1; // increments NumOfUsers by 1 through indirect access
				break;
				
			case 2:
				SecurityFlag = AppointmentSecurityCheck(arrayOfUserID, ListOfData); // assigns the return value of AppointmentSecurityCheck to SecurityFlag
				
				if (SecurityFlag == 1) // If SecurityFlag is one, meaning that the user successfully inputs right details in AppointmentSecurityCheck, UserAppointmentMenu executes.
				{
					UserAppointmentMenu(ListOfApp, arrayOfAppID, numberofApps);
				}
				break;
				
			case 3:
				AskVaxi(); // Chatbot function
				break;
				
			case 4:
				RegMenuSignal = 1; // makes RegMenuSignal == 0 false.
		}
		
	} while (RegMenuSignal == 0);
}
