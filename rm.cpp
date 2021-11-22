#include<stdio.h>
#include<iostream>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
void rm_file(char* filename)
{
    FILE* fp = fopen(filename,"r");
    if(fp == NULL)
	    cout <<"no such file"<<endl;
    else
	    remove(filename);
}

int is_dir1(char* path)
{
    struct stat st;
    stat(path,&st);
    if(S_ISDIR(st.st_mode)){
        return 1;
    }
    else {
        return 0;
    }
}


void rm_dir(char* dirname)
{
    if(is_dir1(dirname)==0){
        cout<<"parameter wrong"<<endl;
	return;
    }
    dirent* filename;
    DIR* dp = opendir(dirname);
    char* path = new char[100];
    while(filename=readdir(dp)){
        memset(path,0,sizeof(path));
	strcpy(path,dirname);
	strcat(path,"/");
	strcat(path,filename->d_name);
	if(strcmp(filename->d_name,".")==0||strcmp(filename->d_name,"..")==0)
		continue;
	else if(is_dir1(path)==1)
		rm_dir(path);
	else
		remove(path);
    }
    closedir(dp);
    rmdir(dirname);
}

/*int main()
{
    char x[10];
    cin >> x;
    rm_dir(x);
}*/
