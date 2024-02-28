#include <iostream>
using namespace std;

template <typename T>
struct Stack
{
    int size;
    T *arr;
    int top;

    Stack(int n)
    {
        top = -1;
        size = n;
        arr = new T[n];
    }

    int Push(T val)
    {
        if (top == size - 1)
        {
            return 0;
        }
        top++;
        arr[top] = val;
        return 1;
    }

    int Pop(T &dp)
    {
        if (top == -1)
        {
            return 0;
        }
        dp = arr[top];
        top--;
        return 1;
    }

    int getMaxSize()
    {
        return size;
    }

    int currentSize()
    {
        return top + 1;
    }

    int isEmpty()
    {
        return top == -1;
    }
    void display(){
        for(int i=0;i<=top;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};


int main()
{
    int n1;
    cout << "Enter the number of elements for stack S1: ";
    cin >> n1;
    Stack<int> s1(n1);
    // Stack<float> s1(n1);
    // Stack<string> s1(n1);
    // Stack<double> s1(n1);
    // Stack<short> s1(n1);

    int ch;
    do
    {
        cout << "\nMenu:\n1.Push\n2.Pop\n3.Get MaxSize\n4.Get CurrentSize\n5.Is Empty?\n6.Display\n7.Exit\n";
        cout << "Enter your choice : ";
        cin >> ch;
        if (ch == 1)
        {
            int val;
            // float val;
            // string val;
            // double val;
            // short val;
            cout << "Enter element: ";
            cin >> val;
            string res = (s1.Push(val)) ? "Added" : "Error";
            cout <<"\n"<< res << endl;
        }
        else if (ch == 2)
        {
            int val;
            // float val;
            // string val;
            // double val;
            // short val;
            s1.Pop(val);
            cout << "Popped value = " << val << endl;
        }
        else if (ch == 3)
        {
            cout << "MaxSize = " << s1.getMaxSize() << endl;
        }
        else if (ch == 4)
        {
            cout << "Current Size = " << s1.currentSize() << endl;
        }
        else if (ch == 5)
        {
            string res = (s1.isEmpty()) ? "Yes" : "No";
            cout << "Is Empty? = " << res << endl;
        }
        else if (ch == 6)
        {
            s1.display();
        }

    } while (ch != 7);

    return 0;
}