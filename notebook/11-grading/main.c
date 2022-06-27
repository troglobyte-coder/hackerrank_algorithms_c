//
// HackerRank folio
// solved by Michael Gene Brockus
//
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

//
// Should return an integer array of student grades
// after processing each grade to see if it's less
// than three or if the grade is up to the next
// multiple of five.
//
// arg-list:
//  -> grades: the grades being passed in
//  -> grades_count: the garden array length
//  -> result_count: the result count
//
int* gradingStudents(int grades_count, int* grades, int* result_count)
{
    *result_count = grades_count;
    for (int iter = 0; iter < grades_count; iter++)
    {
        if (grades[iter] >= 38)
        {
            switch (grades[iter] % 5)
            {
                case 4:
                {
                    grades[iter] += 1;
                    break;
                } // end case
                case 3:
                {
                    grades[iter] += 2;
                    break;
                } // end case

            } // end switch

        } // end if

    } // end for
    return grades;
}

//
// main is where all C programs start
//
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int grades_count = parse_int(ltrim(rtrim(readline())));

    int* grades = malloc(grades_count * sizeof(int));

    for (int i = 0; i < grades_count; i++)
    {
        int grades_item = parse_int(ltrim(rtrim(readline())));

        *(grades + i) = grades_item;
    } // end for

    int result_count;
    int* result = gradingStudents(grades_count, grades, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, "\n");
        } // end if

    } // end for

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
} // end of func

//
// Should readlines of data from the text
// file into the program for use.
//
// arg-list:
//  -> N/A:
//
char* readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true)
    {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        } // end if

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        } // end if

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        } // end if

    } // end while

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        } // end if

    } // end if
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        } // end if
        else
        {
            data[data_length] = '\0';
        } // end else

    } // end else

    return data;
} // end of func

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string refrence being passed in for left trim
//
char* ltrim(char* str)
{
    if (!str)
    {
        return '\0';
    } // end if

    if (!*str)
    {
        return str;
    } // end if

    while (*str != '\0' && isspace(*str))
    {
        str++;
    } // end while

    return str;
} // end of func

//
// Should trim the data read in from the test case
// file being used in this problem.
//
// arg-list:
//  -> str: string refrence being passed in for right trim
//
char* rtrim(char* str)
{
    if (!str)
    {
        return '\0';
    } // end if

    if (!*str)
    {
        return str;
    } // end if

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    } // end while

    *(end + 1) = '\0';

    return str;
} // end of func

//
// Should parse integer values from the data file.
//
// arg-list:
//  -> str: string being parsed into integers
//
int parse_int(char* str)
{
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    } // end if

    return value;
} // end of func
