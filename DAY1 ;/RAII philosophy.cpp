#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
using namespace std;
class File{
    int p;
    public:
    File(const char* path){
        p=open(path,O_WRONLY|O_CREAT|O_TRUNC,0644);
        cout<<"opened"<<endl;
        cout<<"fd value "<<p<<endl;//  here it will print 3 beacuse 1 and 2 are default as i created new file it print 3
    }
    void writee(char* data){
        if(p>=0){
            write(p,data,strlen(data));
        }
    }
    ~File(){
        if(p>=0){
            close(p);
            cout<<" closed"<<endl;
        }
    }
};
int main(){
    File f("user");
    File f1("chaithanya");
    f.writee("hello everyone i am RAII\n");
    f1.writee("These is second file\n");
    cout<<"completed"<<endl;
    write(0,"hello",10);// these is for standared output
}