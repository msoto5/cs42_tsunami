/**
 * @file tsunami.c
 * @author Miguel Soto (miguel@soto.es)
 * @brief Programa con buffer overflow
 * El programa realiza el buffer overflow con la función strcpy. 
 * Este programa se llama a traves del payload.c
 * 
 * @version 1.0
 * @date 2022-07-26
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
    char buffer[16];

    if (argc < 2)
    {
        printf ("ERROR: Introduzca un argumento al programa\n");  
        return 0;
    }
    
    strcpy (buffer, argv[1]);

    return 0;
}