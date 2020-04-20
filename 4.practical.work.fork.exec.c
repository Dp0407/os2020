#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid1 = fork();

    if (pid1 == 0)
    {
        // Begin
        int pid = fork();

        if (pid == 0)
        {
            printf("child_2 after fork() again, launching free -h\n");
            char *args[] = {"free", "-h", NULL};
            sleep(1);
            execvp("free",args);

            printf("Finished launching free -h. \n");
        }
        else
        {
            printf("parent after fork() again, child_2 is %d\n", pid);
        }

        printf("I am child_1 after fork(), launching ps -ef");
        char *args[] = {"/bin/ps", "-ef", NULL};
        sleep(6);
        execvp("/bin/ps",args);
    }
    else printf("parent after fork(), child_1 is %d", pid1);

    return 0;
}

