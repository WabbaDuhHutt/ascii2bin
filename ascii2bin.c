/********************************/
/* Program Name: Fernanado Vega */
/* Author:                      */
/* Date: 02/16/2021             */
/********************************/
/* Description:checksum         */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define byte unsigned char
#define MAX_INT (1 << 30)

int main (int argc, char * argv[], char ** envp)
{
int offset = 0x30;
int number = 0;
int retval = 1;
int digit;
byte ascii_value;

retval = read(STDIN_FILENO, &ascii_value, 1);

while (retval == 1 || ascii_value != '\n'  )
{
    if (ascii_value != '0' && ascii_value != '1' )
    {
        return 1;
    }
    else
    {
        digit = ascii_value - offset;
        number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);
    }
 }

if (number > MAX_INT)
{

    fprintf(stderr, "Error Detected!\n");

    return 1;

 }
 else {

    printf("%u\n", number);

    return 0;

}

}
