#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
using namespace std;

void cp_txt(char* x1,char* x2){
    FILE* fp1 = fopen(x1,"r");
    FILE* fp2 = fopen(x2,"w");
    if(fp1 == NULL || fp2 == NULL)
	    cout <<"no such file"<<endl;
    else{
        char c;
	while((c = fgetc(fp1))!=EOF){
	    fprintf(fp2,"%c",c);
	}
	fclose(fp1);
	fclose(fp2);
    }
}

void cp_file(char* x1,char* x2)
{
    char buffer[1000];
    FILE* fp1 = fopen(x1,"r");
    FILE* fp2 = fopen(x2,"w");
    if(fp1 == NULL || fp2 == NULL)
	    cout << "no such file"<<endl;
    else{
        int k;
	while((k = fread(buffer,1,1000,fp1))>0)
			fwrite(buffer,1,k,fp2);
	fclose(fp1);
	fclose(fp2);
    }
  
}

int is_dir(char* path)
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

void cp_dir(char* x1,char* x2)
{
	
    if(!opendir(x2))
	    mkdir(x2,0777);
    
    dirent* filename;
    DIR* dp = opendir(x1);
    char* path1;
    path1 = new char[100];
    char* path2;
    path2 = new char[100];
    while(filename=readdir(dp)){
        memset(path1,0,sizeof(path1));
	memset(path2,0,sizeof(path2));
	strcpy(path1,x1);
	strcat(path1,"/");
	strcat(path1,filename->d_name);
	strcpy(path2,x2);
	strcat(path2,"/");
	strcat(path2,filename->d_name);
	if(is_dir(path1)){
		if(path1[strlen(path1)-1]!='.')
			cp_dir(path1,path2);
	}
	else
	    cp_file(path1,path2);
    }
    

}

/*int main(){
    char x1[20];
    char x2[20];
    cin >> x1;
    cin >> x2;
    cp_txt(x1,x2);
}*/
