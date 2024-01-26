#include<iostream>
using namespace std;

struct MyStack{
    int max_size;
    int *arr;
    int top;
};

MyStack Initiaize(int n){
    MyStack s;
    s.max_size = n; 
    s.arr = new int(n);//Dynamically allocating memory for n box
    for(int i=0;i<n;i++){
        s.arr[i]=-1;  //Making every box to -1 to avoid garbage
    }
    s.top=-1;   //Intialising the top value is -1
}

int Push(MyStack *s,int a){ //Taking pointer type stack so that the changes happen in original stack also
    if(s->top==s->max_size){
        return 0;
    }

    s->top++;   //Why we are incrementing top first?because we are intialized top as -1
    s->arr[s->top] = a; 
    return 1;
}

void Pop(MyStack *s){
    s->arr[s->top]=NULL; //Making the box to NULL
    //How to delete the memory
    s->top--; 
}

int CurrentSize(MyStack *s){
    return s->top+1; //As top starts from 0 so the size is top+1
}

void IsEmpty(MyStack *s){
    if(s->top==-1){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Not Empty"<<endl;
    }
}



int main(){
    int n1;
    cout<<"ENter the size of Stack"<<endl;
    cin>>n1;

    MyStack s1;
    s1=Initiaize(n1);
    
    int temp;
    for(int i=0;i<n1;i++){
        
        cin>>temp;
        Push(&s1, temp);
    }


    
    return 0;
}