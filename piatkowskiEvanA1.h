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


#include <stdio.h>
#define NUMBER_REVIEWERS 10
#define NUMBER_MOVIES 3
#define MAX_STR 50
#define MAX_WORDS 10

struct reviewStruct {
    char reviewer[MAX_STR];
    int feedback[NUMBER_MOVIES];
};

FILE *openFileForReading(char *fileName);

int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]);

int readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]);

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]);
