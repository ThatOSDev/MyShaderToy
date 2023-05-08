
/*
NOTE - Make sure to define it like this :

#define LOGGER_IMPLEMENTATION
#include "logging.h"

EXAMPLE : logging("INFO : Hello there!");
*/

#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>   // FILE  fopen()   fclose()  wprintf()  fprintf()
#include <string.h>  // strcpy()   strcat()
#include <stdlib.h>  // malloc()   free()
#include <stdarg.h>  // va_start    va_end   va_list
#include <time.h>    // time()   localtime()   tzset()   strftime()
#include <errno.h>   // errno

#define logging(...) _logging(__VA_ARGS__)

void _logging(const char* fmt, ...);

#endif // LOGGING_H

#ifdef LOGGER_IMPLEMENTATION

void _logging(const char* fmt, ...)
{
    char datestr[51];
    time_t t = time(NULL);
    tzset();
    char* fileName = malloc(sizeof(char) * 19);
    strftime(datestr, sizeof(datestr) - 1,  "%m-%d-%Y", localtime(&t));
    strcpy(fileName, "log-");
    strcat(fileName, datestr);
    strcat(fileName, ".txt");
    FILE *file = fopen(fileName, "a+");
    if(file == NULL)
    {
        free(fileName);
        wprintf(L"ERROR : Unable to create log file !!\n");

    } else {
        if(errno == 22)
        {
            errno = 0;
        }
        free(fileName);
        va_list ap;
        strftime(datestr, sizeof(datestr) - 1,  "%b/%d/%Y  %H:%M", localtime(&t));
        fprintf(file, "%s - ", datestr);
        va_start(ap, fmt);
        vfprintf(file, fmt, ap);
        va_end(ap);
        fprintf(file, "\n");
        fclose(file);
    }
}


#endif // LOGGER_IMPLEMENTATION

