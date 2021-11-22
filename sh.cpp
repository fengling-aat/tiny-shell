#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include"sh.h"
using namespace std;

void exe_sh(char* filename)
{
    FILE* fp = fopen(filename,"r");
    int len = strlen(filename);
    if(fp == NULL)
	    cout << "no such file"<<endl;
    else if(filename[len-1]!='h'||filename[len-2]!='s'||filename[len-3]!='.'){
        cout<<"file type wrong"<<endl;
	return;
    }
    else{
        char command[100]={'\0'};
	int position = 0;
	while(fgets(command,100,fp)){
	    
	    int i = 0;
	    for(;command[i]!='\n';++i);
	    command[i]='\0';
	   // cout << "..."<<command<<"..."<<endl;
	    string order = command;
	    if(position==0){
	        if(order.substr(0,7)!="#!/bin/"){
		    cout<<"execute failed"<<endl;
		    break;
		}
	    }
	    else if(command[0]=='#')
		    continue;
	    else if(order.substr(0,4) == "man ")
                read_man(command);
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
	    else if(order.substr(0,6)=="mkdir ")
                read_mkdir(command);
	    else if(order.substr(0,6)=="touch ")
		    read_touch(command);
            else if(order.substr(0,3) == "cp "){
                if(order.substr(0,6)=="cp -r ")
                        read_cpr(command);
                else{
                        read_cp(command);
                }
            }
	    else if(order.substr(0,3) == "sh ")
                read_sh(command);
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
            else
                cout <<"command not found"<<endl;
	    ++position;
        }
	fclose(fp);
    }
}

/*int main()
{
    char x[100];
    cin >> x;
    exe_sh(x);
}*/
