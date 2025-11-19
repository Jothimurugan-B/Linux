#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
        int fd[2];

        pipe(fd);
        printf("fd[0]=%d fd[1]=%d\n",fd[0],fd[1]);

        if(fork()==0)
        {
                char b[20];
                read(fd[0],b,20);
                printf("In child read:\n");
                printf("%s\n",b);

                printf("Enter string in child:\n");
                scanf("%s",b);
                write(fd[1],b,strlen(b)+1);
        }

        else
        {
                char a[20];
                printf("Enter string in parent:\n");
                scanf("%s",a);

                write(fd[1],a,strlen(a)+1);

                sleep(2);

                read(fd[0],a,20);
                printf("In parent read:\n");
                printf("%s\n",a);

        }
}
