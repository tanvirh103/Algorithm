#include<iostream>
using namespace std;
void Merge(int L[], int R[], int A[], int nL, int nR) {
    int i = 0, j = 0, k = 0;
    
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(int A[], int n) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    int L[mid], R[n - mid];

    for (int i = 0; i < mid; i++) {
        L[i] = A[i];
    }

    for (int i = mid; i < n; i++) {
        R[i - mid] = A[i];
    }

    Mergesort(L, mid);
    Mergesort(R, n - mid);
    Merge(L, R, A, mid, n - mid);
}

void print(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<"\t";
    }
    cout<<endl;
}
int main(){
    int array[10]={10,2,56,76,98,12,455,56,87,12};
    Mergesort(array,10);
    print(array,10);
}
