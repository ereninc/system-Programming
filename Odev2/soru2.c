#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <string.h>
#include <stdlib.h> 
#include "fields.h"

int main(int argc, char **argv)
{
    IS is;
    int i;
    if(argc != 3)   { fprintf(stderr, "Dosya adini eksik girdin:\n"); exit(1); }
    //if(argc == "-r")    { printf("2. argument -r"); }
    is = new_inputstruct(argv[2]);
    if (is == NULL) {
        perror(argv[2]);
        exit(1);
    }

    char *argument = argv[1];
    char *s = "-s";
    char *r = "-r";
    char *strcpy = "strcpy";
    char *strcat = "strcat";
    char *sprintf= "sprintf";
    char *gets = "gets";
    char *getpw = "getpw";
    if ((strstr(argument, s) != NULL))
    {
        printf("arg -s\n");
        while(get_line(is) >= 0) {
            for (i = 0; i < is->NF; i++) {
                if ((strstr(is->fields[i], strcpy) != NULL))
                {
                    printf("Satir %d: strcpy() kullanilmis bunun yerine strlcpy() veya strncpy() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], strcat) != NULL))
                {
                    printf("Satir %d: strcat() kullanilmis bunun yerine strlcat() veya strncat() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], sprintf) != NULL))
                {
                    printf("Satir %d: sprintf() kullanilmis bunun yerine snprintf() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], gets) != NULL))
                {
                    printf("Satir %d: gets() kullanilmis bunun yerine fgets() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], getpw) != NULL))
                {
                    printf("Satir %d: getpw() kullanilmis bunun yerine getpwuid() kullanilabilir.\n", is->line);
                }
                
            }
        }
    }

    else if ((strstr(argument, r) != NULL))
    {
        printf("arg -r\n");
        while(get_line(is) >= 0) {
            for (i = 0; i < is->NF; i++) {
                if ((strstr(is->fields[i], strcpy) != NULL))
                {
                    printf("Satir %d: strcpy() kullanilmis bunun yerine strlcpy() veya strncpy() kullanilabilir ve sonlandirma icin yer birakilmali\n", is->line);
                }
                if ((strstr(is->fields[i], strcat) != NULL))
                {
                    printf("Satir %d: strcat() kullanilmis bunun yerine strlcat() veya strncat() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], sprintf) != NULL))
                {
                    printf("Satir %d: sprintf() kullanilmis bunun yerine snprintf() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], gets) != NULL))
                {
                    printf("Satir %d: gets() kullanilmis bunun yerine fgets() kullanilabilir.\n", is->line);
                }
                if ((strstr(is->fields[i], getpw) != NULL))
                {
                    printf("Satir %d: getpw() kullanilmis bunun yerine getpwuid() kullanilabilir.\n", is->line);
                }
            }
        }
    }

    else
    {
        printf("Yanlis argument girildi.");
    }
    
    jettison_inputstruct(is);
    exit(0);
}