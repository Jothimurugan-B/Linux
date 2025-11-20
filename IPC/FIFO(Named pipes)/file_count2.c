//This code receives directory name and count the number of files in directory and then send to process 1
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
        int fd,c;
        char str[20];

//        mkfifo("proc1",0664);

        fd=open("proc1",O_RDONLY);
        read(fd,str,sizeof(str));
        printf("str = %s\n",str);

        DIR *df;
        struct dirent *p;
        int count=0;

        df=opendir(str);

        while(p=readdir(df))
                count++;


        close(fd);

        fd=open("proc1",O_WRONLY);
        write(fd,&count,sizeof(count));
}
