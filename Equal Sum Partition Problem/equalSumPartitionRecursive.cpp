#include<bits/stdc++.h>
using namespace std;

bool equalSumPartition(int *arr, int n, int sum){
    if(sum == 0){
        return true;
    }
    if(n ==0){
        return false;
    }
    if(arr[n - 1] <= sum ){
        return (equalSumPartition(arr, n-1, sum-arr[n-1]) || equalSumPartition(arr, n-1, sum));
    }
    else{
        return equalSumPartition(arr, n-1, sum);
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 2 != 0){
        cout << "Not able to split!" << endl;
    }
    else{
        if(equalSumPartition(arr, n, sum/2)){
            cout << "Able to split!" << endl;
        }
    }
}