#include <iostream>
using namespace std;

class StudInfo
{
private:
    string name;
    int age;
    string department;
    string year;

public:
    // Reading student data
    void ReadStudentData()
    {

        cout << "Enter student name " << endl;
        cin >> name;

        cout << "Enter age" << endl;
        cin >> age;

        cout << "Enter Department\n";
        cin >> department;

        cout << "Enter Year\n";
        cin >> year;
    }

    // Printing the data
    void PrintData()
    {

        cout << "Student name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Year: " << year << endl;
    }

};
 
int main()
{
    int n;
    cout<<"Enter the no. of Students"<<endl;
    cin>>n;

    //Making object of student class of size n
    StudInfo student[n];

    //Reading the value
    for(int i=0;i<n;i++){
        cout<<"Entering data of student no. "<<i+1<<endl;
        student[i].ReadStudentData();
    }

    cout<<"\n Printing the data"<<endl;

    //Printing the info
    for(int i=0;i<n;i++){
        cout<<"\nPrinting the data of Student no. "<<i+1<<endl;
        student[i].PrintData();
    }

    return 0;
}