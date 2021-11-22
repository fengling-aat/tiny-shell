#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

#define YELLOW  "\033[33m"      /* Yellow */
#define WHITE   "\033[37m"      /* White */
using namespace std;
int is_dir2(char* path)
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

void ls_a()
{
    char* path = NULL;
    path = getcwd(NULL,0);
    if(is_dir2(path)==0){
        cout<<"you are not under a dir"<<endl;
        return;
    }
    dirent* filename;
    DIR* dp = opendir(path);
    char* path1 = new char[100];
    while(filename = readdir(dp)){
	memset(path1,0,sizeof(path1));
	strcat(path1,path);
	strcat(path1,"/");
	strcat(path1,filename->d_name);
	if(is_dir2(path1)==1)
		cout<<YELLOW<<filename->d_name<<"    ";
	else
       	        cout<<WHITE<<filename->d_name<<"    ";
    }
    cout << endl;
    closedir(dp);
    free(path);

}

void ls()
{
    char* path = NULL;
    path = getcwd(NULL,0);
    if(is_dir2(path)==0){
        cout<<"you are not under a dir"<<endl;
	return;
    }
    dirent* filename;
    DIR* dp = opendir(path);
    char* path1 = new char[100];
    while(filename = readdir(dp)){
	memset(path1,0,sizeof(path1));
        strcat(path1,path);
        strcat(path1,"/");
        strcat(path1,filename->d_name);
	if(filename->d_name[0]=='.')
		continue;
	else if(is_dir2(path1)==1)
		cout<<YELLOW<<filename->d_name<<"    ";
	else
                cout<<WHITE<<filename->d_name<<"    ";
    }
    cout << endl;
    closedir(dp);
    free(path);
}
/*int main()
{
    ls_a();
    ls();
}*/
