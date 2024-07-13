/*********************************************************************************************************	
This	is	to	certify	that	this	project	is	my	own	work,	based	on	my	personal	efforts	in	studying	and	applying	the	concepts	
learned.		I	have	constructed	the	functions	and	their	respective	algorithms	and	corresponding	code	by	myself.		The	
program	was	run,	tested,	and	debugged	by	my	own	efforts.		I	further	certify	that	I	have	not	copied	in	part	or	whole	or	
otherwise	plagiarized	the	work	of	other	students	and/or	persons.

																								Carl Vincent BLix P. Lingat,	DLSU	ID#	12208221	
*********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50


/*
	Notes:
	1. All strings are sizes are added by 1 to allow for the null byte to be stored.
	2. It is already assumed that the users have already taken their first shot because second and booster doses were listed as optional.
	3. It is assumed that the text file for the chatbot, named Vaxi.txt always exists.
	4. Vaxi is the name of the Chatbot.
	5. userID and password to access DataManagementMenu is 1911 and AnimoLaSalle!
*/
typedef char string11[11];

struct userInfo
{ // struct for User-related information
	int userID;
	char password[11]; 
	char name[21];
	char address[31];
	int contactNum;
	string11 sex;
	string11 firstDoseDate;
	string11 firstDoseVaccine;
	string11 firstDoseLocation;
	string11 secondDoseDate;
	string11 secondDoseVaccine;
	string11 secondDoseLocation;
	string11 boosterDoseDate;
	string11 boosterDoseVaccine;
	string11 boosterDoseLocation;
};

struct appointmentInfo
{ // struct for Appointment-related information
	int appID;
	char name[21];
	string11 location;
	string11 vaccine;
	string11 date;
	char time[7];
	char dose[10];
};

#include "Lingat_VaccinationRegistrationMenu.c"
#include "Lingat_DataManagementMenu.c"

// main function
int 
main ()
{
	// i is counter variable, mainSignal is a variable for looping evaluations, and numberOfUsers/numberofApps are the total number of users and appointments respectively.
	int i, userInput, mainSignal = 0, numberOfUsers = 0, numberofApps = 0;
	int arrayOfUserID[SIZE]; // array of UserIDs, useful for checking if UserID is used or not.
	int arrayOfAppID[SIZE]; // array of AppIDs, useful for checking if AppID is used or not.
	struct userInfo ListOfData[SIZE]; // array of struct userInfo
	struct appointmentInfo ListOfApp[SIZE]; // array of struct appointmentInfo
	
	// initialize all elements of UserID and AppID arrays to 0.
	for (i = 0; i < SIZE; i++)
	{
		arrayOfUserID[i] = 0;
		arrayOfAppID[i] = 0;
	}
	
	// loops until user wants to end the program.
	do
	{
		system("cls");
		
		printf("Welcome to the Vaccination Registration App!\n\n");
		printf("What would you like to access?\n");
		printf("[1] Vaccination Registration Menu\n");
		printf("[2] Data Management Menu (Admins Only)\n");
		printf("[3] Exit\n\n");
		
		// input validation
		do
		{
			scanf("%d", &userInput);
		} while (userInput != 1 && userInput != 2 && userInput != 3);
		
		
		switch (userInput)
		{
			case 1:
				VaccinationRegistrationMenu(ListOfData, arrayOfUserID, &numberOfUsers, ListOfApp, arrayOfAppID, &numberofApps); // Vaccination Registration Menu will be executed.
				break;
			
			case 2:
				DataManagementMenu(ListOfData, arrayOfUserID, &numberOfUsers, ListOfApp, arrayOfAppID, &numberofApps); // Data Management Menu will be executed.
				break;
			
			case 3:
				mainSignal = 1; // Terminates the loop by making mainSignal == 0 false.
		}
	} while (mainSignal == 0);
	
	system("cls");

	printf("Stay safe always!\n");
	
	
	return 0;
}
