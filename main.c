//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
      FILE *exerciseFile = fopen(EXERCISEFILEPATH, "r");
      if (exerciseFile == NULL) {
        printf("Error: Could not open %s\n", EXERCISEFILEPATH);
        return 1;
    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	if (health_data.remainingCalories <= 0 ){
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	// Display the list of exercises
                loadExercises(exerciseFile);
                break;
                
            case 2:
            	// Display the list of diets
                loadDiets(dietFile);
                break;
                
            case 3:
            	
                break;
                
            case 4:
                printf("Exit the system.\n");
                printf("=======================================================================\n");
                saveData("health_data.txt", &health_data); // save data
                return 0;
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while ( );

    return 0;
}

