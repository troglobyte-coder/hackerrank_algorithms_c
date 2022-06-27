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
// Should compare the rating between vector array
// 'a' and vector array 'b', then it returns a
// vector with the rating values for the two.
//
// arg-list:
//  -> s: the starting point in the process
//  -> t: the ending point in the process
//  -> a: number of apples in the set
//  -> b: number of oarnges in the set
//  -> apples: array of apples
//  -> oranges: array of oranges
//  -> apples_count: array length for apples
//  -> oranges_count: array length for oranges
//
void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
    int count1 = 0;
    int count2 = 0;
    int suma = 0, sumo = 0;

    for (int iter = 0; iter < apples_count; iter++)
    {
        suma = a + *(apples + iter);
        if (s <= suma && suma <= t)
        {
            count1++;
        } // end if

    } // end for
    printf("%i\n", count1);

    for (int iter = 0; iter < oranges_count; iter++)
    {
        sumo = b + *(oranges + iter);
        if (s <= sumo && sumo <= t)
        {
            count2++;
        } // end if

    } // end for
    printf("%i\n", count2);
} // end of func

//
// main is where all C programs start
//
int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int s = parse_int(*(first_multiple_input + 0));

    int t = parse_int(*(first_multiple_input + 1));

    char** second_multiple_input = split_string(rtrim(readline()));

    int a = parse_int(*(second_multiple_input + 0));

    int b = parse_int(*(second_multiple_input + 1));

    char** third_multiple_input = split_string(rtrim(readline()));

    int m = parse_int(*(third_multiple_input + 0));

    int n = parse_int(*(third_multiple_input + 1));

    char** apples_temp = split_string(rtrim(readline()));

    int* apples = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        int apples_item = parse_int(*(apples_temp + i));

        *(apples + i) = apples_item;
    } // end for

    char** oranges_temp = split_string(rtrim(readline()));

    int* oranges = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int oranges_item = parse_int(*(oranges_temp + i));

        *(oranges + i) = oranges_item;
    } // end for

    countApplesAndOranges(s, t, a, b, m, apples, n, oranges);

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
