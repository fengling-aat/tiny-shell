#include<iostream>
#include<string.h>
#include<string>
#include"command.h"

#define GREEN   "\033[32m"      /* Green */
#define BAISE   "\033[37m"      /* White */
using namespace std;

void read_man(char* x)
{
    char command[100]={'\0'};
    for(int i = 0;x[i+4]!='\0';++i)
	    command[i] = x[i+4];
    explain(command);
}

void read_cat(char* x)
{
    char filename[100] = {'\0'};
    for(int i = 0;x[i+4]!='\0';++i)
	    filename[i] = x[i+4];
    show(filename);
}

void read_wc(char* x,int a)
{
    char filename[100] = {'\0'};
    for(int i = 0;x[i+6]!='\0';++i)
	    filename[i] = x[i+6];
    if(a == 1)
	    read_c(filename);
    else if(a == 2)
	    read_w(filename);
    else
	    read_l(filename);
}

void read_cmp(char* x)
{
    char filename1[100] = {'\0'};
    char filename2[100] = {'\0'};
    int flag = 0;
    int i = 0;
    for(;x[i+4]!='\0';++i){
        if(x[i+4] == ' '&& x[i+5]!='\0'){
	    flag = 1;
	    break;
	}
	else
	    filename1[i] = x[i+4];
    }
    if(flag == 0)
	    cout << "parameter wrong"<<endl;
    else{
        for(int j = i+5;x[j]!='\0';++j)
		filename2[j-i-5] =x[j];
        compare(filename1,filename2);
    }
}

void read_cp(char* x)
{
    char filename1[100] = {'\0'};
    char filename2[100] = {'\0'};
    int flag = 0;
    int i = 0;
    for(;x[i+3]!='\0';++i){
	    if(x[i+3] == ' '&& x[i+4]!='\0'){
	        flag = 1;
		break;
	    }
	    else
		    filename1[i] = x[i+3];
    }
    if(flag == 0)
	    cout << "parameter wrong"<<endl;
    else{
        for(int j = i+4;x[j]!='\0';++j)
		filename2[j-i-4]=x[j];
	cp_file(filename1,filename2);
    }
}

void read_cpr(char* x)
{
    char filename1[100] = {'\0'};
    char filename2[100] = {'\0'};
    int flag = 0;
    int i = 0;
    for(;x[i+6]!='\0';++i){
            if(x[i+6] == ' '&& x[i+7]!='\0'){
                flag = 1;
                break;
            }
            else
                    filename1[i] = x[i+6];
    }
    if(flag == 0)
            cout << "parameter wrong"<<endl;
    else{
        for(int j = i+7;x[j]!='\0';++j)
                filename2[j-i-7]=x[j];
        if(is_dir(filename1)==0||is_dir(filename2)==0)
		cout << "parameter wrong"<<endl;
	else{
        cp_dir(filename1,filename2);
	}
    }

}

void read_sh(char* x)
{
    char filename[100] = {'\0'};
    for(int i = 0;x[i+3]!='\0';++i)
	    filename[i] = x[i+3];
    exe_sh(filename);
}

void read_rm(char* x)
{
    char filename[100] ={'\0'};
    for(int i = 0;x[i+3]!='\0';++i)
	    filename[i] = x[i+3];
    rm_file(filename);
}

void read_rmr(char* x)
{
    char dirname[100]={'\0'};
    for(int i = 0;x[i+6]!='\0';++i)
	    dirname[i] = x[i+6];
    rm_dir(dirname);
}

void order()
{
    char command[100];
    char* head = gethead();
    while(true){
        cout <<GREEN<<head;
	cout << BAISE;
	cin.getline(command,100);
        string order = command;
	if(order.substr(0,4) == "man ")
		read_man(command);
	else if(order.substr(0,3) == "cp "){
		if(order.substr(0,6)=="cp -r ")
			read_cpr(command);
		else{
               	        read_cp(command);
		}
	}
	else if(strcmp(command,"ls")==0)
		ls();
	else if(strcmp(command,"ls -a")==0)
		ls_a();
	else if(order.substr(0,3) == "rm "){
		if(order.substr(0,6)=="rm -r ")
			read_rmr(command);
		else
			read_rm(command);
	}
	else if(order.substr(0,4) == "cat ")
		read_cat(command);
	else if(order.substr(0,3) == "wc "){
		if(order.substr(0,6) == "wc -c ")
			read_wc(command,1);
		else if(order.substr(0,6) == "wc -w ")
			read_wc(command,2);
		else if(order.substr(0,6) == "wc -l ")
			read_wc(command,3);
		else
			cout <<"parameter wrong"<<endl;

	}
	else if(order.substr(0,4) == "cmp ")
		read_cmp(command);
	else if(strcmp(command,"exit") == 0){
	    cout <<"Exit......."<<endl;
	    break;
	}
	else if(order.substr(0,6)=="mkdir ")
		read_mkdir(command);
	else if(order.substr(0,6)=="touch ")
		read_touch(command);
	else if(order.substr(0,3) == "sh ")
		read_sh(command);
	else
		cout <<"command not found"<<endl;
    }
}

int main()
{
    order();
    return 0;
}
