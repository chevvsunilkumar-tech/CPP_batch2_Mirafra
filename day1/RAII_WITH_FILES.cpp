#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
class file
{
int fd;

public:
file(const  char *path ,char *content)
{
fd=open(path,O_WRONLY);
cout<<"file opened\n";
cout<<"fd "<<fd<<endl;

write(fd,content,strlen(content));
}

void write1(const char *p)
{
write(fd,p,strlen(p));
cout<<" written succesfully\n";

}

~file()
{
if(fd>=0){
close(fd);

cout<<"file is closed\n";
}

}

};


int main()
{
file f("ex.txt","i am good"),f2("ex1.txt","hi everyone");

f.write1("\n hi hello");
}
