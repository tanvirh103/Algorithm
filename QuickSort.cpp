#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    for(int j=low+1;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i],&arr[low]);
    return i;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        cout<<"After Iteration "<<"pivot :"<<arr[pi]<<endl;
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int array[10]={20,14,54,76,12,56,97,75,65,34};
    quickSort(array,0,9);
    print(array,10);
}
