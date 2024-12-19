//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
  while (exercise_list_size < MAX_EXERCISES &&
           fscanf(file, "%49s %d", exercise_list[exercise_list_size].exercise_name, 
                  &exercise_list[exercise_list_size].calories_burned_per_minute) == 2) {
        exercise_list_size++;
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    for (i = 0; i < exercise_list_size; i++) {
        printf("%d. %s (%d kcal/min)\n", i + 1, 
		exercise_list[i].exercise_name, 
		exercise_list[i].calories_burned_per_minute);
    }
    printf("0. Exit\n");


    // ToCode: to enter the exercise tto be chosen with exit option
      do {
        printf("Enter the number of the exercise you want to select (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting exercise selection.\n");
            return;
        }

        if (choice < 1 || choice > exercise_list_size) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice < 1 || choice > exercise_list_size);
 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    int caloriesBurned = exercise_list[choice - 1].calories_burned_per_minute * duration;
    health_data->total_calories_burned += caloriesBurned;
    printf("You burned %d calories by doing %s for %d minutes.\n", 
	caloriesBurned, exercise_list[choice - 1].exercise_name, duration);

}
