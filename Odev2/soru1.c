#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <string.h>
#include <stdlib.h> 
 
int main(void) 
{ 
    pid_t pid = fork(); 
    if (pid >= 0)
    { 
        if (pid == 0)
        { 
            //
        } 
        else // Parent process 
        {
            extern etext, edata, end;
            char s1[] = "lorem ipsum";
            char *heap = malloc(4*sizeof(*heap));
            printf("\nData bolumu  : baslangic= 0x%lx, boyut= %zi Byte",&edata ,&edata);
            printf("\nHeap bolumu  : baslangic= 0x%lx, boyut= %zi Byte",heap ,&heap);
            printf("\nStack bolumu : baslangic= 0x%lx, boyut= %zi Byte",s1 ,&s1);
        } 
    } 
    else // fork failed 
    { 
        printf("\n HATA\n"); 
        return 1; 
    } 
    return 0; 
} 