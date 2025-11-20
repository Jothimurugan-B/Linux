//This code send directory name and receives file count
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main()
{
        int fd,c;
        char str[20];

        mkfifo("proc1",0664);
        printf("Enter dir name:\n");
        scanf("%s",str);

        fd=open("proc1",O_WRONLY);

        write(fd,str,strlen(str)+1);
        sleep(1);
        close(fd);

        fd=open("proc1",O_RDONLY);
        read(fd,&c,sizeof(c));

        printf("number of files:%d\n",c);
}
