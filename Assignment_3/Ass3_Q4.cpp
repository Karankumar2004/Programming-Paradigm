#include <iostream>
using namespace std;

class MyStack
{
private:
    int max_size;
    int *arr;
    int top; //Accessing this in the main that's it is in the public
    static int count; //Static why?? //ek hi copy har jagah share hoga
    static const int Max_Stack = 5;
public:
    
    //Making Constructor
    MyStack(int size){
        if(count>= Max_Stack){
            cout<<"Maximum limit reached"<<endl;
            max_size = 0;
            arr = nullptr;
            top = -1;
        }
        
        max_size = size;
        arr = new int[size];
        top=-1;
        count++;
    }

    //Copy Constructor
    MyStack(MyStack &A){
        max_size = A.max_size;
        arr = new int[A.max_size]; //Dynamically allocating the same size of memory as A
        for(int i=0;i<max_size;i++){
            arr[i] = A.arr[i];      //Copying the value
        }
        top = A.top;
        count++;
    }

    //Operator overloading
    MyStack operator+(const MyStack &st){
        MyStack st_3(max_size + st.max_size); //Making the size of resultant stack is the sum two stack
        
        //Pushing the elements of first stack into result stack
        for(int i=0;i<=top;i++){
            st_3.Push(arr[i]);
        }

        //Pushing the elements of second stack into result stack
        for(int i=0; i<=st.top;i++){
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
    
    int Top() { //For accessing the top element
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

    static int getCount() {
        return count;
    }
};

int MyStack :: count=0; //We can acsess it without creating any object

int main(){
    
    int n1;
    cout<<"ENter the size of Stack"<<endl;
    cin>>n1;

    MyStack s1(n1); //Creating object of MyStack class of size n
    
    cout<<"Enter the stack value\n";
    for(int i=0;i<n1;i++){ //Pushing the value into the stack
        int temp;
        cin>>temp;
        s1.Push(temp);
    }
    
    cout<<"\nPrinting the top element \n";
    cout<<s1.Top();

    cout<<"\nSize of stack: "<<s1.CurrentSize();

    s1.Pop();
    cout<<"\nPrinting the top element after popping\n";
    cout<<s1.Top();

    cout<<"\nSize of stack: "<<s1.CurrentSize();
    s1.IsEmpty();
    cout<<"\nNo. of Stack: "<<MyStack::getCount()<<endl;

   /**********Copy Constructor************/
   cout<<"\nStack-2: ";
   MyStack s2 = s1;
   for(int i=0;i<4;i++){
    cout<<s2.Top()<<"  ";
    s2.Pop();
   }
   cout<<"\nNo. of Stack: "<<MyStack::getCount()<<endl;

   /**********Assignement Operator************/
 /*  MyStack s3(4);
   for(int i=3;i>=0;i--){
    s3.Push(s1.Top());
    s1.Pop();
   } 
   for(int i=0;i<4;i++){
    cout<<s3.Top()<<"  ";
    s3.Pop();
   }
    cout<<"\nNo. of Stack: "<<MyStack::getCount()<<endl;
*/
    cout<<"\nStack-3: ";
    MyStack s3 = s1+s2;
    for(int i=0;i<8;i++){
    cout<<s3.Top()<<"  ";
    s3.Pop();
   }



    return 0;
}