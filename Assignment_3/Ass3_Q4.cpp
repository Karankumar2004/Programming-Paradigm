#include <iostream>
using namespace std;

class MyStack
{
private:
    int max_size;
    int *arr;
    int top;          // Accessing this in the main that's it is in the public
    static int count; // Static why?? //ek hi copy har jagah share hoga
    static const int Max_Stack = 5;

public:
    // Making Constructor
    MyStack(int size)
    {
        if (count >= Max_Stack)
        {
            cout << "Maximum limit reached" << endl;
            max_size = 0;
            arr = nullptr;
            top = -1;
        }

        // otherwise
        max_size = size;
        arr = new int[size];
        top = -1;
        count++;
    }

    // Copy Constructor
    MyStack(MyStack &A)
    {
        max_size = A.max_size;
        arr = new int[A.max_size]; // Dynamically allocating the same size of memory as A
        for (int i = 0; i < max_size; i++)
        {
            arr[i] = A.arr[i]; // Copying the value
        }
        top = A.top;
        count++;
    }

    // Operator overloading
    MyStack operator+(const MyStack &st)
    {
        MyStack st_3(max_size + st.max_size); // Making the size of resultant stack is the sum of two stack

        // Pushing the elements of first stack into result stack
        for (int i = 0; i <= top; i++)
        {
            st_3.Push(arr[i]);
        }

        // Pushing the elements of second stack into result stack
        for (int i = 0; i <= st.top; i++)
        {
            st_3.Push(st.arr[i]);
        }
        return st_3;
    }

    int Push(int a)
    {
        if (top == max_size)
        {
            return 0;
        }

        top++; // Why we are incrementing top first?because we are intialized top as -1
        arr[top] = a;
        return 1;
    }

    void Pop()
    {
        arr[top] = -1; // Making the box to NULL
        // How to delete the memory
        top--;
    }

    int Top()
    { // For accessing the top element
        return arr[top];
    }

    int CurrentSize()
    {
        return top + 1; // As top starts from 0 so the size is top+1
    }

    void IsEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "\n Not Empty" << endl;
        }
    }

    void show() // For printing the values
    {
        cout << "Stack Content: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static int getCount()
    {
        return count;
    }
};

int MyStack ::count = 0; // We can acsess it without creating any object

int main()
{

    MyStack stack1(5);
    stack1.Push(11);
    stack1.Push(44);
    stack1.Push(56);
    stack1.Push(55);
    stack1.show();

    MyStack stack2(3);
    stack2.Push(75);
    stack2.Push(25);
    stack2.Push(85);
    stack2.show();

    MyStack stack3 = stack1 + stack2;
    stack3.show();

    // Attempt to create more stacks than the maximum allowed
    MyStack stack4(2);
    MyStack stack5(8);
    MyStack stack6(11);
    MyStack stack7(87);
    MyStack stack8(16);

    return 0;
}