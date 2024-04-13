import java.io.DataInputStream;
import java.io.IOException;

class Student {
    String name;
    int age;
    String department;
    int year;

    Student()
	{

	}

    Student(String name,int age, String department,int year) {
        this.name = name;
	this.age = age;
        this.department = department;
	this.year = year;
    }

public void readData() throws IOException
{
	DataInputStream dis = new DataInputStream(System.in);

        System.out.println("Enter your name");
        String n = dis.readLine();

        System.out.println("Enter your age");
        int a = Integer.parseInt(dis.readLine());	
	
	System.out.println("Enter your department");
        String d = dis.readLine();

        System.out.println("Enter your year");
        int y = Integer.parseInt(dis.readLine());	

	this.name = n;
	this.age = a;
        this.department = d;
	this.year = y;

}

public void printData()
{
	System.out.println("\nName : " + this.name +"\nAge : " + this.age +"\nDepartment : " + this.department +"\nYear : " + this.year+"\n");
}

}

public class ques2 {
    public static void main(String[] args) throws IOException {
        
	Student s = new Student();
	s.readData();
	s.printData();
    }
}