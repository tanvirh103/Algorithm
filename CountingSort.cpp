#include <iostream>
using namespace std;
void countingSort(int arr[], int n, int k) {
    int C[k+1] = {0};  
    for (int i = 0; i < n; i++) {
        C[arr[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    } 
    int B[n];
    for (int i = n-1; i >= 0; i--) {
        B[C[arr[i]]-1] = arr[i];
        C[arr[i]]--;
    }  
    for (int i = 0; i < n; i++) {
        arr[i] = B[i];
    }
}

int main() {
    int arr[] = {5,6,3,1,7,8,9,0,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k = 9;

    cout << "Before sorting: "<<endl;;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    countingSort(arr, n, k);
    cout<<endl;
    cout << "After sorting:"<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
