/*
 Student Name: Evan Piatkowski
 Student ID: 1136319
 Due Date: Feb 6, 2022
 Course: CIS*2500
 I have exclusive control over this submission via my password.
 By including this header comment, I certify that:
 1) I have read and understood the policy on academic integrity.
 2) I have completed Moodle's module on academic integrity.
 3) I have achieved at least 80% on the academic integrity quiz
 I assert that this work is my own. I have appropriate acknowledged
 any and all material that I have used, be it directly quoted or
 paraphrased. Furthermore, I certify that this assignment was written
 by me in its entirety.
*/

#include "piatkowskiEvanA1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUMBER_REVIEWERS 10
#define NUMBER_MOVIES 3
#define MAX_STR 50
#define MAX_WORDS 10

FILE *openFileForReading(char *fileName){
    FILE *fileOpen;
    fileOpen = fopen(fileName, "r");
    if (!fileOpen){
    return NULL;
    }
    else{
        return fileOpen; 
    } 
}

// bugged
int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]){
    int counter;
    int loop1, loop2;

    // Checks if NULL file pointer
    if(file == NULL){
        return 0;
    }

    for (loop1  = 0; loop1<NUMBER_MOVIES; loop1++){
        for (loop2 = 0; loop2 < MAX_STR; loop2++){
            fscanf(file, "%s \n",)
        }
    }
}

int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]){
    int count = 1;
    char name[MAX_STR];
    char feed1, feed2, feed3;

    if(file == NULL){
        return 0;
    }

    while(fscanf(file, "%s %c %c %c", name, &feed1, &feed2, &feed3)==4){
        strcpy(reviews[count].reviewer, name); 
        //checking each review and assigning a 1 or 0
        //feedback for reviewer 1
        if(feed1 == 'Y' || feed1 == 'y'){
            reviews[count].feedback[0] = 1;
        }else{
            reviews[count].feedback[0] = 0;
        }
        //feedback for reviewer 2
        if(feed2 == 'Y' || feed2 == 'y'){
            reviews[count].feedback[1] = 1;
        }else{
            reviews[count].feedback[1] = 0;
        }
        //feedback for reviewer 3
        if(feed3 == 'Y' || feed3 == 'y'){
            reviews[count].feedback[2] = 1;
        }else{
            reviews[count].feedback[2] = 0;
        }
        count++;
    }

    if(count == NUMBER_REVIEWERS){
        return 1;
    }else{
        return 0;
    }
}

/* ////    KEEPS PRINTING WRONG NUMBERS COMPLETE REWRITE UNDERNEATH /////
int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]){
    int loop, mostCrit=3;
    int count = 0;

    for(loop = 0; loop < NUMBER_REVIEWERS; loop++){
        // sum of all the reviews
        int sumOfReviews = reviews[loop].feedback[0] + reviews[loop].feedback[1] + reviews[loop].feedback[2];
        // the lowest review value
        if(sumOfReviews < mostCrit){
            mostCrit = sumOfReviews;
        }
        for(loop = 0; loop < NUMBER_REVIEWERS; loop++){
            int sumOfReviews = reviews[loop].feedback[0] + reviews[loop].feedback[1] + reviews[loop].feedback[2]; 
            if(sumOfReviews == mostCrit){
                strcpy(mostCriticalReviewers[count],reviews[loop].reviewer);
                count++;
            }
        }
        return count;
    }
}
*/

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]){
    int counter, sum, highest = 0; 
    int loop1, loop2;
    char holder[NUMBER_REVIEWERS];

    // finds most critical review for each person and saves it to an array that holds all
    for(loop1 = 0; loop1<NUMBER_REVIEWERS; loop1++){
        for(loop2 = 0; loop2 < NUMBER_MOVIES; loop2){
            if(reviews[loop1].feedback[loop2] == 0){
                counter++; 
            }
        }
        // writing most critical to array
        holder[loop1] = counter;
        // reset counter
        counter = 0;
    }
    for(loop1 = 0; loop1<NUMBER_REVIEWERS; loop1++){
        if(holder[loop1]>highest){
            highest = holder[loop1];
        }
    }
    if(highest > 0){
        for(loop1 = 0; loop1 < NUMBER_REVIEWERS; loop1++){
            if(holder[loop1]){
                strcpy(mostCriticalReviewers[sum], reviews[loop1].reviewer);
                sum++;
            }
        }
    }
    return sum;
}