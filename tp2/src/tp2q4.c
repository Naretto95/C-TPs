/**
 * @file tp2q4.c
 * @brief Reads a name, first name and date of birth, then prints them back.
 * @author Lilian Naretto
 */

#include <stdio.h>

#define NAME_MAX_LEN 32
#define MONTH_MAX_LEN 16

int main(void) {
    char last_name[NAME_MAX_LEN];
    char first_name[NAME_MAX_LEN];
    char month[MONTH_MAX_LEN];
    int day, year;

    printf("Enter your last name: ");
    scanf("%s", last_name);
    printf("Enter your first name: ");
    scanf("%s", first_name);

    printf("Enter your date of birth (day month year): ");
    scanf("%d", &day);
    scanf("%s", month);
    scanf("%d", &year);

    printf("\nYou entered:\n");
    printf("Name: %s\n", last_name);
    printf("First name: %s\n", first_name);
    printf("Date of birth: %d %s %d\n", day, month, year);
    return 0;
}
