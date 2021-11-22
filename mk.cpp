#include<stdio.h>
#include<sys/types.h>
#include<iostream>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
using namespace std;

void my_mkdir(char* dirname)
{
    char* path = NULL;
    path = getcwd(NULL,0);
    dirent* filename;
    DIR* dp = opendir(path);
    int flag = 0;
    while(filename = readdir(dp)){
        if(strcmp(filename->d_name,dirname)==0){
	    cout<<"create failed:dir already exist"<<endl;
	    flag = 1;
	    break;
	}
    }
    if(flag == 0)
	    mkdir(dirname,0777);
    closedir(dp);
    free(path);
  
}

void mkfile(char* name)
{
    char* path = NULL;
    path = getcwd(NULL,0);
    dirent* filename;
    DIR* dp = opendir(path);
    int flag = 0;
    while(filename = readdir(dp)){
        if(strcmp(filename->d_name,name)==0){
            cout<<"create failed:file already exist"<<endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        FILE* fp = fopen(name,"w");
	if(fp == NULL)
		cout <<"create failed"<<endl;
	else
		fclose(fp);
    }
    closedir(dp);
    free(path);

}

void read_mkdir(char*x )
{
    char dirname[100]={'\0'};
    for(int i = 0;x[i+6]!='\0';++i)
	    dirname[i] = x[i+6];
    my_mkdir(dirname);
}

void read_touch(char* x)
{
    char filename[100]={'\0'};
    for(int i = 0;x[i+6]!='\0';++i)
	    filename[i] = x[i+6];
    mkfile(filename);
}

/*int main()
{
    char x[20];
    cin >> x;
    mkfile(x);
}*/
