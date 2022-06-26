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

//
// Should process a gven a time in 12-hour AM/PM
// format, convert it to military (24-hour) time
// and return that as the result.
//
// arg-list:
//  -> s: A single string thatrepresents a time
//
char* timeConversion(char* s)
{
    scanf("%10s", s);
    if (s[8] == 'A' || s[8] == 'P')
    {
        
        if (s[8] == 'A')
        {
            s[8] = '\0';
            s[9] = '\0';
            
            char stra[3];
            sprintf(stra, "%c%c", s[0], s[1]);
            int hoursa = atoi(stra);

            if(hoursa == 12){
                hoursa = 0;
                char milstra[3];
                sprintf(milstra, "%02d", hoursa);
                s[0] = milstra[0];
                s[1] = milstra[1];
            } // end if
            printf("%s\n", s);
        } // end if
        else
        {
            s[8] = '\0';
            s[9] = '\0';
            
            char str[3];
            sprintf(str, "%c%c", s[0], s[1]);
            int hours;
            hours = atoi(str);
            int milhours;
            milhours = hours + 12;
            if(milhours == 24)
            {
                milhours = 12;
            } // end if
            char milstr[3];
            sprintf(milstr, "%02d", milhours);
            s[0] = milstr[0];
            s[1] = milstr[1];
            printf("%s\n", s);
        } // end else

    } // end if
    return s;
} // end of func

//
// main is where all C programs start
//
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

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
