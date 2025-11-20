#include<stdio.h>
#include<dirent.h>

int main()
{
        char str[20];
        int count=0;

        printf("Enter dir name:\n");
        scanf("%s",str);

        DIR *fd;
        struct dirent *p;

        fd=opendir(str);

        while((p=readdir(fd))!=NULL)
                count++;

        printf("file count=%d\n",count);
}
