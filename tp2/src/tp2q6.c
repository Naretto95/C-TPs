/**
 * @file tp2q6.c
 * @brief Reads a calendar date and prints the date of the following day.
 * @author Lilian Naretto
 */

#include <stdio.h>

/**
 * @brief Tells whether a given year is a leap year.
 * @param year the year to test
 * @return 1 if leap, 0 otherwise
 */
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/**
 * @brief Returns the number of days in a given month of a given year.
 * @param month month number (1-12)
 * @param year the year, used to handle February in leap years
 * @return the number of days in that month
 */
int days_in_month(int month, int year) {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

int main(void) {
    int day, month, year;

    printf("Enter a date (day month year): ");
    scanf("%d", &day);
    scanf("%d", &month);
    scanf("%d", &year);

    if (day < 1 || month < 1 || month > 12 || day > days_in_month(month, year)) {
        printf("Invalid date.\n");
        return 0;
    }

    day++;
    if (day > days_in_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    printf("Next day: %d %d %d\n", day, month, year);
    return 0;
}
