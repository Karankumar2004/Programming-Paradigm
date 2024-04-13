import java.io.DataInputStream;
import java.io.IOException;

class Person {
    String name;
    int age;
    String gender;
    String dept;

    Person(String name, int age, String gender, String dept) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.dept = dept;
    }

    public void printDetails() {
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Gender: " + this.gender);
        System.out.println("Department: " + this.dept);
    }
}

class Student extends Person {
    int year;

    Student(String name, int age, String gender, String dept, int year) {
        super(name, age, gender, dept);
        this.year = year;
    }

    @Override
    public void printDetails() {
        super.printDetails();
        System.out.println("Year: " + this.year);
    }
}

class Professor extends Person {
    int courseLoad;
    double salary;

    Professor(String name, int age, String gender, String dept, int courseLoad, double salary) {
        super(name, age, gender, dept);
        this.courseLoad = courseLoad;
        this.salary = salary;
    }

    @Override
    public void printDetails() {
        super.printDetails();
        System.out.println("Course Load: " + this.courseLoad);
        System.out.println("Salary: " + this.salary);
    }
}

public class ques3 {
    public static void main(String[] args) throws IOException {
        DataInputStream dis = new DataInputStream(System.in);

        System.out.println("Enter student details (name, age, gender, dept, year):");
        Student s = new Student(dis.readLine(), Integer.parseInt(dis.readLine()), dis.readLine(), dis.readLine(), Integer.parseInt(dis.readLine()));
        s.printDetails();

        System.out.println("\nEnter professor details (name, age, gender, dept, course load, salary):");
        Professor p = new Professor(dis.readLine(), Integer.parseInt(dis.readLine()), dis.readLine(), dis.readLine(), Integer.parseInt(dis.readLine()), Double.parseDouble(dis.readLine()));
        p.printDetails();
    }
}