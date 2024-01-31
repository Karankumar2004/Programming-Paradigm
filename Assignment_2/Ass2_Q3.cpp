#include <iostream>
using namespace std;

//Taking element in struct
struct takeValue{
    int num1;
    int num2;
};

void swap_genric(takeValue *data){//We have to pass as a pointer to change it globally
    int temp = data->num1;
    data->num1=data->num2;
    data->num2=temp;
}

int main() {
    takeValue data;
    cout<<"Enter Num1: ";
    cin>>data.num1;

    cout<<"Enter Num2: ";
    cin>>data.num2;

    swap_genric(&data);

    cout<<data.num1<<" "<<data.num2;
    return 0;
}
