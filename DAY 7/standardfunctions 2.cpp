#include<iostream>
#include<functional>
using namespace std;
class NotificationManager{
    function<void(string)> typeerasure;
    public:
    void setNotifier(function<void(string)> p){
        typeerasure=move(p);
    }
    void notify(string ss){
        typeerasure(ss);
    }
};
// normal method
void emailNotification(string s){
    cout<<"EMail Notification: "<<s<<endl;
}
// functor with state
struct smsNotification{
    int maxlength;
    smsNotification(int l):maxlength(l){}
    void operator()(string s){
        if(s.size()<maxlength){
            cout<<"SMS Notification "<<s<<endl;
        }
        else{
            cout<<"Size limit out"<<endl;
        }
    }
};
int main(){
    NotificationManager manager;
    
    // normal function
    manager.setNotifier(emailNotification);
    manager.notify("Hello Manager\n");
    
    // functor with state   
    manager.setNotifier(smsNotification{25});
    manager.notify("Hello\n");
    
    // lambda with capture
    int count=0;
    manager.setNotifier([&count](string s){
        if(++count<3){
            cout<<"push"<<s<<endl;
        }
    });
    manager.notify("hello");
    manager.notify("Hi");
}
