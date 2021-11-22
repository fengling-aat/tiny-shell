#include<pwd.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
char* gethead()
{
    passwd* pwd;
    pwd = getpwuid(getuid());
    //printf("当前登陆的用户名为：%s\n", pwd->pw_name);
    char hostname[20]={'\0'};
    gethostname(hostname,sizeof(hostname));
    //printf("当前登陆的hostname为：%s\n", hostname);
    char* head = new char[100];
    memset(head,0,sizeof(head));
    strcat(head,pwd->pw_name);
    strcat(head,"@");
    strcat(head,hostname);
    strcat(head,":~$ ");
   // printf("%s\n",head);
    return head;
}

/*int main()
{
    char* x = gethead();
    printf("%s\n",x);
}*/
