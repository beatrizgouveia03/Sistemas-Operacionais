#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{

    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        printf("Erro ao criar processo\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Esta é a execução do filho\n");
        printf("Esperando...\n");
        sleep(10);
        printf("Voltou!\n");
        execlp("/bin/ls", "ls", "-l", NULL);
    }  
    else
    {
        wait(NULL);
        printf("Processo-filho finalizado\n");
    }

    return 0;
}