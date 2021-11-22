#ifndef _COMMAND_H_
#define _COMMAND_H_

void compare(char* filename1,char* filename2);
void show(char *filename);
void explain(char* x);
void read_c(char* filename);
void read_w(char* filename);
void read_l(char* filename);
void cp_txt(char* x1,char* x2);
void cp_file(char* x1,char* x2);
void cp_dir(char* x1,char* x2);
int is_dir(char* path);
void exe_sh(char* filename);
void rm_dir(char* dirname);
void rm_file(char* filename);
void ls_a();
void ls();
void my_mkdir(char* dirname);
void mkfile(char* name);
void read_mkdir(char* x);
void read_touch(char* x);
char* gethead();
#endif
