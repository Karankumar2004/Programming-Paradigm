#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
private:
    int max_size;
    T *arr;

    int top; // Accessing this in the main that's it is in the public
public:
    // Making Constructor
    MyStack(int size)
    {
        max_size = size;
        arr = new int[size];
        top = -1;
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
    }

    int Push(T a)
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

    T Top()
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
};
int main()
{

    int n1;
    cout << "ENter the size of Stack" << endl;
    cin >> n1;

    MyStack<int> s1(n1); // Creating object of MyStack class of size n
    // MyStack<float> s1(n1);
    // MyStack<short> s1(n1);
    // MyStack<double> s1(n1);
    // MyStack<struct> s1(n1);

    cout << "Enter the stack value\n";
    for (int i = 0; i < n1; i++)
    { // Pushing the value into the stack
        cout << "\n check \n";
        int val;
        // float val;
        // string val;
        // double val;
        // short val;
        cin >> val;
        s1.Push(val);
    }

    cout << "\nPrinting the top element \n";
    cout << s1.Top();

    cout << "\nSize of stack: " << s1.CurrentSize();

    s1.Pop();
    cout << "\nPrinting the top element after popping\n";
    cout << s1.Top();

    cout << "\nSize of stack: " << s1.CurrentSize();
    s1.IsEmpty();



    /**********Copy Constructor************/
    /* MyStack<int> s2 = s1;
     for(int i=0;i<4;i++){
      s2.Top();
      s2.Pop();
     }
     */
    /**********Assignement Operator************/
    /*  MyStack<int> s3(4);
      for(int i=3;i>=0;i--){
       s3.Push(s1.Top());
       s1.Pop();
      }
      for(int i=0;i<4;i++){
       cout<<s3.Top()<<"  ";
       s3.Pop();
      }
   */

    return 0;
}