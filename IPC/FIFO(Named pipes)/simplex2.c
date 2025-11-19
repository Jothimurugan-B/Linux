//Reading code
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

        fd=open("fifo",O_RDONLY);

        read(fd,str,sizeof(str));

        printf("string read:\n");
        printf("%s\n",str);


}
