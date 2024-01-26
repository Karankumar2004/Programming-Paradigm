#include<iostream>
using namespace std;

struct StudInfo{
    string name;
    int age;
    string department;
    string year;
};

void ReadStudentData(StudInfo a[],int n){
    for(int i=0;i<n;i++){
    cout<<"Enter student name "<<i+1<<endl;
    cin>>a[i].name;
    cout<<"Enter age"<<endl;
    cin>>a[i].age;
    cout<<"Enter Department\n";
    cin>>a[i].department;
    cout<<"Enter Year\n";
    cin>>a[i].year;
    }
}

void PrintData(StudInfo a[],int n){
    for(int i=0;i<n;i++){
        cout<<i+1<<"Student name: "<<a[i].name<<endl;
        cout<<"Age: "<<a[i].age<<endl;
        cout<<"Department: "<<a[i].department<<endl;
        cout<<"Year: "<<a[i].year<<endl;
    }
}

int main(){
    int n;
    cout<<"Number of student"<<endl;
    cin>>n;

    StudInfo a[n];
    ReadStudentData(a,n);
    PrintData(a,n);
    
    return 0;
}