#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void show(char *filename)
{
    FILE* fp = fopen(filename,"r");
    if(fp == NULL)
	    cout << "no such file"<<endl;
    else{
	char c;
	while((c = fgetc(fp))!=EOF)
		cout << c;
        fclose(fp);
    }
}

/*int main()
{
    char x[20];
    cin >> x;
    show(x);
}*/
