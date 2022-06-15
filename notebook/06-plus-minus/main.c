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

int parse_int(char*);

//
// Given an array of integers, calculate the
// ratios of its elements that are positive,
// negative, and zero. Print the decimal
// value of each fraction on a new line with
// 6 places after the decimal.
//
// Print the ratios of positive, negative and
// zero values in the array. Each value should
// be printed on a separate line with 6 digits
// after the decimal. The function should not
// return a value.
//
// arg-list:
//  -> arr: the array being passed in
//  -> arr_count: the array length
//
void plusMinus(int arr_count, int* arr)
{
    float fr1=0,fr2=0,fr3=0;
    for(int arr_i = 0; arr_i < arr_count; arr_i++)
    {
       scanf("%d",&arr[arr_i]);
    } // end for

    for(int arr_i = 0; arr_i < arr_count; arr_i++)
    {
        if(arr[arr_i]>0)
        {
            fr1++;
        } // end if
        else if(arr[arr_i]<0)
        {
            fr2++;
        } // end else if
        else if(arr[arr_i]==0)
        {
            fr3++;
        } // end else if

    } // end for

    printf("%.6f\n", fr1 / arr_count);
    printf("%.6f\n", fr2 / arr_count);
    printf("%.6f\n", fr3 / arr_count);
} // end of func

//
// main is where all C programs start
//
int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    } // end for

    plusMinus(n, arr);

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
