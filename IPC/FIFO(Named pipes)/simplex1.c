//Writing code
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
        int fd;
        char str[20];

        mkfifo("fifo",0664);

        fd=open("fifo",O_WRONLY);

        printf("Enter string to write:\n");
        scanf("%s",str);

        write(fd,str,strlen(str)+1);
}
