#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Q1
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}
//Q2
int sumOfInt(int n){
    if(n==1){
        return 1;
    }else{
        return n+sumOfInt(n-1);
    }
}
//Q3
int compareString(char s1[], char s2[],int i){

    if(s1[i]=='\0' && s2[i]=='\0'){
        return 0;
    }else if(s1[i] > s2[i]){
        return -1;
    }else if(s2[i] > s1[i]){
        return 1;
    }else{
        return compareString(s1,s2,++i);
        }


}
//Q4
int largestNum(int arr[],int size,int i,int large){
    if(size==1) return arr[i];
   
    if(i==size-1){
            return large;
    }
   
    else {
        if(arr[i] >= large){
          large = arr[i];
            return largestNum(arr,size,++i, large);
        }
        else{
            return largestNum(arr,size,++i, large);
        }
    }


}
//Q5
int HCFOfTwoNum(int n1,int n2){
    if(n1%n2==0) return n2;
    else{
        int temp = n2;
        n2 = n1%n2;
        return HCFOfTwoNum(temp, n2);
    }
}

// }
//Q6
int Search(int arr[],int n,int l,int i){
    if(n==0){
        return 0;
    }else if(arr[i]==l){
        return 1;
    }else if(i==n-1 && arr[i]!=l){
        return 0;
    }else{
        return Search(arr,n,l,++i);
    }
}
//Q7
void PrintReverse(int arr[], int size,int i){

        //base case
        if(i==0) return;

        //print the data
        printf("%d\t", arr[i]);

        //recursive call
        PrintReverse(arr,size,++i);
}
//Q8
int checkPalindrome(char s1[], int size, int i){
    //Base case
    if(size==0 || size==1 || i==(size/2)+1) return 1;
    else if(s1[i]!=s1[size-i-1]){
        return 0;
    }
    return checkPalindrome(s1,size,++i);
}
//Q9
void replaceC1byC2(char s1[], char c1,char c2,int i,int size){
    
    //base case
    if(i==size) return; 
    //Condition of the question
    if(s1[i]==c1) s1[i]=c2;
   //Recursive call and also it is tail recursion
    replaceC1byC2(s1,c1,c2,++i,size);
}

//Q10
void Sorting(int arr[],int size, int i){
        if(size==0) return;

        for(int i=0;i<size;i++){
        if(arr[i]>arr[size]){
        int temp = arr[i];
        arr[i] = arr[size];
        arr[size] = temp;
}
}
        Sorting(arr,size-1,i);
}
//Q11
//Making node structure
typedef struct Node{
    int element;
    struct Node *next;
}Node;
//Function to implement or add nodes in LL
//Adding element in start of LL
Node *addNodeAtStart(Node **start, int elem)
{
    Node *temp = (struct Node *)malloc(sizeof(Node));

    temp->element = elem;
    temp->next = *start; // taken start as pointer that why *start
    *start = temp;

    return temp;
}

void print(Node *start)
{
    Node *temp = start;

    printf("Start -> ");
    while (temp != NULL)
    {
        printf("%d ", temp->element);
        printf(" -> ");
        temp = temp->next;
    }
    printf(" NULL ");
    printf("\n");
}

Node* SortLL(Node **start){
    
}
int main(){
    char s1[] = "Ammeri";
    char s2[] = "Ammer";

    printf("%d", compareString(s1,s2,0));

    int arr[] = {1,2,3,4,5,6};
    int check = Search(arr,6,7,0);
    if(check==0) printf("false");
    else printf("true");

    //Question 8
    char s1[5] = "nitik";
    printf("%d", checkPalindrome(s1,5,0));

    // //Question 9
    char s1[8]="karkakak";
    char c2 = 'a',c1='k';
    replaceC1byC2(s1,c1,c2,0,8);
    for(int i=0;i<8;i++) printf("%c", s1[i]);

    //Question 11
    Node *LL = NULL;
    Node* start = LL;

    addNodeAtStart(&start, 3);
    addNodeAtStart(&start, 5);
    print(start);
    return 0;
}