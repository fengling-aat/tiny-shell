#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void compare(char* filename1,char* filename2)
{
    FILE* fp1 = fopen(filename1,"r");
    FILE* fp2 = fopen(filename2,"r");
    if(fp1==NULL ||fp2 ==NULL)
	    cout <<"no such file"<<endl;
    else{
        char c1,c2;
	int line_no = 1;
	int flag = 0;
	while((c1 = fgetc(fp1))!=EOF && (c2=fgetc(fp2))!=EOF){
	    if(c1 != c2){
		flag = 1;
	        cout<<"line "<<line_no<<":"<<endl;
		cout <<"first file:"<< c1 << endl;
		cout <<"second file:"<< c2<< endl;
		break;
	    }
	    else if(c1 == '\n')
		    line_no += 1;
	}
	if(flag == 0 && c1 == EOF){
		char c3;
		c3 = fgetc(fp2);
		if(c3 == EOF)
			cout <<"two files are the same"<<endl;
		else
			cout <<"file1 is the same with part of file2,but file1 is shorter"<<endl;
	}
	if(flag == 0 && c2 == EOF)
		cout <<"file2 is the same with part of file1,but file2 is shorter"<<endl;
	
        fclose(fp1);
	fclose(fp2);
    }
}

/*int main(){
    char x1[20];
    char x2[20];
    cin >> x1;
    cin >> x2;
    compare(x1,x2);
    return 0;
}*/

