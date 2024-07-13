#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	ExportAllData allows user to export all data into a file.
	@param userInfo - array of type userInfo containing all the data of the users in the program
	@param dNumOfUsers - total number of users in the program, for comparison purposes
	@param ListOfApp - array of type appointmentInfo containing all the data of the appointments in the program
	@param dNumOfApps - total number of appointments in the program, for comparison purposes
*/
void 
ExportAllData(struct userInfo ListOfData[], 
					int dNumOfUsers, 
					struct appointmentInfo ListOfApp[], 
					int dNumOfApps)
{
	FILE *Users; // file pointer for user-related file
	FILE *Apps; // file pointer for appointment-related file
	FILE *Chatbot; // file pointer for chatbot-related file
	FILE *Vaxi; // file pointer of the chatbot contents itself
	char UserFileName[30]; // string for the user file name
	char AppointmentFileName[30]; // string for the appointment file name
	char ChatbotFileName[30]; // string for the chatbot file name
	char strFileInput[81]; // string for extracting contents of Vaxi.txt
	char strQA[26][81]; // string to contain contents of Vaxi.txt
	int i, dCounter = 0; // counter variables
	
	system("cls");
	printf("Input file name (Users):\n");
	scanf("%s", UserFileName); // asks for the file name
	
	Users = fopen(UserFileName, "w"); // opens or creates the user file in write mode
	
	// writes the contents of ListOfData until dNumOfUsers
	for (i = 0; i < dNumOfUsers; i++)
	{
		fprintf(Users, "%d %s\n", ListOfData[i].userID, ListOfData[i].password);
		fprintf(Users, "%s\n", ListOfData[i].name);
		fprintf(Users, "%s\n", ListOfData[i].address);
		fprintf(Users, "%d\n", ListOfData[i].contactNum);
		fprintf(Users, "%s\n", ListOfData[i].sex);
		fprintf(Users, "%s %s %s\n", ListOfData[i].firstDoseLocation, ListOfData[i].firstDoseDate, ListOfData[i].firstDoseVaccine);
		fprintf(Users, "%s %s %s\n", ListOfData[i].secondDoseLocation, ListOfData[i].secondDoseDate, ListOfData[i].secondDoseVaccine);
		fprintf(Users, "%s %s %s\n\n", ListOfData[i].boosterDoseLocation, ListOfData[i].boosterDoseDate, ListOfData[i].boosterDoseVaccine);		
	}
	
	printf("\nInput file name (Appointments):\n");
	scanf("%s", AppointmentFileName); // asks for the file name
	
	Apps = fopen(AppointmentFileName, "w"); // opens or creates the appointment file in write mode
	
	// writes the contents of ListOfApp until dNumOfApps
	for (i = 0; i < dNumOfApps; i++)
	{
		fprintf(Apps, "%d\n", ListOfApp[i].appID);
		fprintf(Apps, "%s\n", ListOfApp[i].name);
		fprintf(Apps, "%s\n", ListOfApp[i].location);
		fprintf(Apps, "%s\n", ListOfApp[i].vaccine);
		fprintf(Apps, "%s\n", ListOfApp[i].date);
		fprintf(Apps, "%s\n", ListOfApp[i].time);
		fprintf(Apps, "%s\n\n", ListOfApp[i].dose);
	}
	
	printf("\nInput file name (Chatbot):\n");
	scanf("%s", ChatbotFileName); // asks for the file name
	
	Vaxi = fopen("Vaxi.txt", "r"); // opens Vaxi.txt in read mode
	Chatbot = fopen(ChatbotFileName, "w"); // opens or creates the chatbot file in write mode
	
	while ( fgets(strFileInput, 81, Vaxi) != NULL) // stores the contents of Vaxi.txt into strQA
	{
		strFileInput[ (int) strlen(strFileInput) - 1] = '\0';
		strcpy(strQA[dCounter], strFileInput);
		dCounter++;
	}
	
	for (i = 0; i < dCounter; i++)
	{
		fprintf(Chatbot, "%s\n", strQA[i]); // prints the contents of strQA to the file
	}
	
	// closes all the opened files.
	fclose(Users);
	fclose(Apps);
	fclose(Vaxi);
	fclose(Chatbot);
	

}


/*
	ImportData allows the user to import data from a text file.
	@param ListOfData - array of type userInfo to store the user data.
	@param arrayOfUserID - array of UserIDs to store the UserID for validation purposes.
	@param dNumOfUsers - to be incremented everytime there is a new set of data
	@param arrayOfAppID - array of AppIDs to store the AppID for validation purposes
	@param dNumOfApps - to be incremented everytime there is a new set of data
*/

void 
ImportData(struct userInfo ListOfData[], 
				int arrayOfUserID[], 
				int* dNumOfUsers, 
				struct appointmentInfo ListOfApp[],
				int arrayOfAppID[],
				int* dNumOfApps)
{
	FILE *Users; // file to read user data
	FILE *Apps; // file to read appointment data
	char strUsersFile[30]; // file name for users file
	char strAppsFile[30]; // file name for appointment file
	char s; // to start the reading process
	int dInput; // for the user to choose whether to import users, appointments, or quit
	
	system("cls");
	printf("What do you want to import?\n");
	printf("[1] - Users\n[2] - Appointments\n[3] - Quit\n");
	
	do
	{
		scanf("%d", &dInput);
	} while (dInput != 1 && dInput != 2 && dInput != 3);
	
	switch(dInput)
	{
		// allows the user to import user dat afrom a text file
		case 1:
			printf("Input the name of the users file:\n");
			scanf("%s", strUsersFile); // gets the file name
			
			Users = fopen(strUsersFile, "r"); // opens the file in read mode
			
			if (Users == NULL) // will not allow the program to read if file does not exist
			{
				printf("File does not exist!\n");
				system("pause");
			}
			
			else // execute if file does exist
			{
				while((s=fgetc(Users)) != EOF) // scans the information until EOF
				{
					fscanf(Users, "%d", &ListOfData[*dNumOfUsers].userID);
					arrayOfUserID[*dNumOfUsers] = ListOfData[*dNumOfUsers].userID; //assigns userID to the arrayOfUserID
					fflush(stdin);
					
					arrayOfUserID[*dNumOfUsers] = ListOfData[*dNumOfUsers].userID;
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].password);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].name);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].address);
					
					fflush(stdin);
					
					fscanf(Users, "%d", &ListOfData[*dNumOfUsers].contactNum);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].sex);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].firstDoseDate);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].firstDoseVaccine);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].firstDoseLocation);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].secondDoseDate);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].secondDoseVaccine);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].secondDoseLocation);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].boosterDoseDate);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].boosterDoseVaccine);
					
					fflush(stdin);
					
					fscanf(Users, "%s", ListOfData[*dNumOfUsers].boosterDoseLocation);
					
					fflush(stdin);
					
					*dNumOfUsers+=1; // increments so that data will not be lost
				}
				
				system("cls");
				printf("Imported.\n");
				system("pause");
			}
			break;
			
		case 2:
			printf("Input the name of the appointments file:\n");
			scanf("%s", strAppsFile); // asks for the file name
			
			Apps = fopen(strAppsFile, "r");
			
			if (Apps == NULL) // will not allow the program to read if file does not exist
			{
				printf("File does not exist!\n");
				system("pause");
			}
			
			else
			{
				// imports data until EOF
				while ((s=fgetc(Apps)) != EOF)
				{
					fscanf(Apps, "%d", &ListOfApp[*dNumOfApps].appID);
					fflush(stdin);
					
					arrayOfAppID[*dNumOfApps] = ListOfApp[*dNumOfApps].appID; // assigns imported appID to arrayOfAppID
					
					fscanf(Apps, "%s", ListOfApp[*dNumOfApps].name);
					fflush(stdin);
					
					fscanf(Apps, "%s", ListOfApp[*dNumOfApps].location);
					fflush(stdin);
					
					fscanf(Apps, "%s", ListOfApp[*dNumOfApps].vaccine);
					fflush(stdin);
					
					fscanf(Apps, "%s", ListOfApp[*dNumOfApps].date);
					fflush(stdin);
					
					fscanf(Apps, "%s", ListOfApp[*dNumOfApps].time);
					fflush(stdin);
					
					fscanf(Apps, "%s", ListOfApp[*dNumOfApps].dose);
					fflush(stdin);
					
					*dNumOfApps+=1; // increments to prevent data loss
				}
				
				system("cls");
				printf("Imported.\n");
				system("pause");
			}
			
			break;
			
		case 3: // exits the function
			break;
	}
}
