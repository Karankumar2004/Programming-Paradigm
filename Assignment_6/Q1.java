import java.io.DataInputStream;
import java.io.IOException;

class Student {
    String name;
    String rollNumber;

    Student(String name, String rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    public void display() {
        System.out.println("Name: " + this.name + ", Roll Number: " + this.rollNumber);
    }
}

public class ques1 {
    public static void main(String[] args) throws IOException {
        DataInputStream dis = new DataInputStream(System.in);

        System.out.println("Enter the number of students:");
        int N = Integer.parseInt(dis.readLine());

        Student[] students = new Student[N];

        for (int i = 0; i < N; i++) {
            System.out.println("Enter the name of student " + (i+1) + ":");
            String name = dis.readLine();

            System.out.println("Enter the roll number of student " + (i+1) + ":");
            String rollNumber = dis.readLine();

            students[i] = new Student(name, rollNumber);
        }

        System.out.println("\nStudent Details:");
        for (Student student : students) {
            student.display();
        }
    }
}