#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    char gender;

public:
    Person(const string &name, int age, char gender)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void displayProfile()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Student : public Person
{
private:
    string dept;
    int year;

public:
    Student(const string &name, int age, char gender, const string &dept, int year)
        : Person(name, age, gender), dept(dept), year(year) {}

    void displayDetails()
    {
        displayProfile();
        cout << "Department: " << dept << endl;
        cout << "Year: " << year << endl;
    }
};

class Clerk : public Person
{
private:
    int workLoad;
    double salary;

public:
    Clerk(const string &name, int age, char gender, int workLoad, double salary)
        : Person(name, age, gender), workLoad(workLoad), salary(salary) {}

    void displayDetails()
    {
        displayProfile();
        cout << "Workload: " << workLoad << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Professor : public Person
{
private:
    string dept;
    int courseLoad;
    double salary;

public:
    Professor(const string &name, int age, char gender, const string &dept, int courseLoad, double salary)
        : Person(name, age, gender), dept(dept), courseLoad(courseLoad), salary(salary) {}

    void displayDetails()
    {
        displayProfile();
        cout << "Department: " << dept << endl;
        cout << "Course Load: " << courseLoad << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    // Creating objects of different classes
    Student student("Alice", 20, 'F', "Computer Science", 3);
    Clerk clerk("Bob", 35, 'M', 40, 50000);
    Professor professor("Charlie", 45, 'M', "Mathematics", 4, 80000);

    // Displaying details of each object
    cout << "Student Details:" << endl;
    student.displayDetails();
    cout << endl;

    cout << "Clerk Details:" << endl;
    clerk.displayDetails();
    cout << endl;

    cout << "Professor Details:" << endl;
    professor.displayDetails();
    cout << endl;

    return 0;
}
