#include<iostream>
#include<string.h>
using namespace std;

void explain(char* x)
{
    if(strcmp(x,"cp")==0){
	cout <<"cp (-r) file1 file2"<<endl;
	cout <<"功能：将目录或文件file1复制成目录或文件file2"<<endl;
	cout <<"说明：括号中为参数，即cp命令可为cp file1 file2或者cp –r file1 file2。若命令为cp –r file1 file2，则需要复制file1目录下的所有内容"<<endl;
    }
    else if(strcmp(x,"cmp")==0){
        cout <<"cmp file1 file2"<<endl;
	cout <<"功能：比较文件1和文件2"<<endl;
	cout <<"说明：cmp命令不需要实现参数。当相互比较的两个文件完全一样时，该指令不会显示任何信息。"<<endl;
	cout <<"      若发现有所差异，命令会显示出第一个不同处的字符和行数编号。当作为参数的file1或者file2实际上不存在时，Shell应提示用户文件不存在"<<endl;
    }
    else if(strcmp(x,"wc")==0){
        cout <<"wc (-c/-w/-l) file1"<<endl;
	cout <<"功能：统计file1中的字节数/字数/行数"<<endl;
	cout <<"说明：与cp命令不同，wc命令的参数在每次输入时是必选的，即每次输入的格式是wc –c file1或wc –w file1或wc –l file1。"<<endl;
	cout <<"功能分别为统计file1中的字节数/字数/行数"<<endl;
    }
    else if(strcmp(x,"cat")==0){
        cout <<"cat file1"<<endl;
	cout <<"功能：显示file1中的内容"<<endl;
	cout <<"说明：cat命令不需要实现参数"<<endl;
    }
    else if(strcmp(x,"man")==0){
        cout <<"man  命令1"<<endl;
	cout <<"功能：显示命令1的说明文档"<<endl;
    }
    else if(strcmp(x,"mkdir")==0){
        cout <<"mkdir dirname"<<endl;
        cout <<"功能：在当前目录下创建目录"<<endl;	
    }
    else if(strcmp(x,"touch")==0){
        cout <<"touch filename"<<endl;
	cout <<"功能：在当前目录下创建文件"<<endl;
    }
    else if(strcmp(x,"ls")==0){
        cout<<"ls:显示当前目录下未被隐藏的文件和目录"<<endl;
	cout<<"ls -a:显示当前目录下的所有文件"<<endl;
    }
    else if(strcmp(x,"rm")==0){
        cout<<"rm filename:删除文件"<<endl;
	cout<<"rm -r dirname:删除目录"<<endl;
	cout<<"参数-r选择与否对应的删除对象不同"<<endl;
    }
    else if(strcmp(x,"sh")==0){
        cout <<"sh shellfilename"<<endl;
	cout<<"逐行进行sh文件中的命令"<<endl;
    }
    else
	cout << "command not exist"<<endl;
}

/*int main(){
    char x[20];
    cin >> x;
    explain(x);
    return 0;
}*/
