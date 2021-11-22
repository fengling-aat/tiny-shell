#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 1000
using namespace std;

void read_c(char* filename)
{
    FILE* fp = fopen(filename,"r");
    if(fp == NULL)
	    cout << "no such file"<<endl;
    else{
	int i = 0;
	fseek(fp,0,SEEK_END);
	i = ftell(fp);
	cout << "There are "<<i<<" bytes"<<endl;
	fclose(fp);
    }
}

int is_cut(char x)
{
    if(x ==' ' ||x == '\t'||x =='\n')
	    return 1;
    else
	    return 0;
}

void read_w(char* filename)
{
    FILE* fp = fopen(filename,"r");
    if(fp == NULL)
	    cout << "no such file"<<endl;
    else{
        int result = 0;
        char c;
	char pre_c = ' ';
        while((c = fgetc(fp))!= EOF){
	    if(is_cut(c)==1 && is_cut(pre_c)==0)
		    ++result;
	    pre_c = c;
	}
	fclose(fp);
	cout << "There are "<<result<<" words"<<endl;
    }
}

void read_l(char* filename)
{
    FILE* fp = fopen(filename,"r");
    if(fp == NULL)
	    cout << "no such file"<<endl;
    else{
        char c;
	int result = 0;
	while((c = fgetc(fp))!= EOF){
	    if(c == '\n')
		    ++result;
	}
	cout << "There are "<<result << " lines"<<endl;
	fclose(fp);
    }
}

/*int main()
{
    char x[20];
    cin.getline(x,20);
    read_c(x);
    read_w(x);
    read_l(x);
    return 0;
}*/
