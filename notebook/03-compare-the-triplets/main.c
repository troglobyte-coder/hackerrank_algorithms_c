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
char** split_string(char*);

//
// Should compare the rating between array
// 'a' and array 'b', then it returns a
// with the rating values for the two.
//
// arg-list:
//  -> a: first array being compared
//  -> b: second array being compared
//  -> a_count: number of items in array one
//  -> b_count: number of items in array two
//  -> result_count: number of results
//
int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count)
{
    //
    // here we set the result count to 2 and
    // allocate an array to hole the points
    // for bob and alice, we set both to zero
    // so we don't have any pointer errors.
    //
    *result_count = 2;
    int *points = malloc(*result_count * sizeof(int));
    *(points + 0) = *(points + 1) = 0;

    for (int iter = 0; iter < a_count; ++iter)
    {
        //
        // here we do a check to see if both
        // values from 'a' and 'b' are the same
        // and if so skip to the next value in
        // the vector else continue pass the if
        // and process the two values.
        //
        if (a[iter] == b[iter])
        {
            continue;
        } // end if

        //
        // here we check to see if the value in
        // 'a' index is greater than 'b' index
        // if so add one point to alice else add
        // one to bob's rating.
        //
        (a[iter] < b[iter])? points[1]++ : points[0]++;
    } // end for
    return points;
} // end of func

//
// main is where all C programs start
//
int main(void)
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        char* a_item_endptr;
        char* a_item_str = *(a_temp + i);
        int a_item = strtol(a_item_str, &a_item_endptr, 10);

        if (a_item_endptr == a_item_str || *a_item_endptr != '\0')
        {
            exit(EXIT_FAILURE);
        } // end if

        *(a + i) = a_item;
    } // end for

    int a_count = 3;

    char** b_temp = split_string(rtrim(readline()));

    int* b = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        char* b_item_endptr;
        char* b_item_str = *(b_temp + i);
        int b_item = strtol(b_item_str, &b_item_endptr, 10);

        if (b_item_endptr == b_item_str || *b_item_endptr != '\0')
        {
            exit(EXIT_FAILURE);
        } // end if

        *(b + i) = b_item;
    } // end for

    int b_count = 3;

    int result_count;
    int* result = compareTriplets(a_count, a, b_count, b, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, " ");
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
// Should split the data into tokens so they can be used
// in the problem.
//
// arg-list:
//  -> str: string being split
//
char** split_string(char* str)
{
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits)
        {
            return splits;
        } // end if

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    } // end while

    return splits;
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
