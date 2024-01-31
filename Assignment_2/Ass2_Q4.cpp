#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot = arr[end]; //taking ending element as pivot
    int i=start-1; //for tracking the index of swaped element

    for(int j=start;j<end;j++){ //As end element is taken as pivot
        if(arr[j]<pivot){ //If element is lesser than pivot
            i++;
            //Swaping
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
        //Now, placing the pivot at their correct place
        i++;
        int temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;
        return i;
    }
}

void quickSort(int arr[],int start,int end){
    if(start < end){ //array ka size grater than one jone chayie
        int piIdx = partition(arr,start,end);

        //left half
        quickSort(arr, start, piIdx-1);
        //Right half
        quickSort(arr,piIdx+1,end);
    }
}

int main(){
    int arr[6] = {3,4,7,0,2,11};
    quickSort(arr,0,5);
    int i=0;
    while(i<6){
        cout<<arr[i]<<"  ";
        i++;
    }

    return 0;
}