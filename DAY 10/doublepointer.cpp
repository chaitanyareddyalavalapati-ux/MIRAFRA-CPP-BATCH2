#include<iostream>
#include<vector>
using namespace std;
struct  sensormanager{
    string name;
    int number;
    int** dp;
    vector<int>size;
    vector<string> sensorname;
    sensormanager(){
        cout<<"enter the number of sensors data"<<endl;
         cin>>number;
        dp= new int*[number];
        // allocating the memory
        cout<<"array of pointers memory is created"<<endl;
        for(int i=0;i<number;i++){
            cout<<"Enter the number elemnts in each 1Darray "<<endl;
            int n;
            cin>>n;
            cout<<"Enter the name of the sensor : "<<endl;
            cin.ignore();
            getline(cin,name);
            sensorname.push_back(name);
            dp[i]=new int[n];
            size.push_back(n);
            temperature(dp[i],n);
         }
    }
    void display(){
        cout<<"Now accessing the values of individual sensors"<<endl;
        for(int i=0;i<number;i++){
            cout<<sensorname[i]<<"values:"<<endl;
            for(int j=0;j<size[i];j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    ~sensormanager(){
        // deallocating the array
        for(int i=0;i<number;i++){
            delete[] dp[i];
        }
        delete[] dp;
        cout<<"destructor"<<endl;
    }
    void temperature(int*v,int p){
        cout<<"Gathering  sensor values"<<endl;
        for(int i=0;i<p;i++){
            cin>>v[i];
        }
    }
};
int main(){
    sensormanager s;
    s.display();
}