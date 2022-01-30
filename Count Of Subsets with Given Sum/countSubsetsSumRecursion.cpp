#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr, int n, int sum){
    if(sum == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(arr[n-1] <= sum){
        return countSubsetSum(arr, n-1, sum-arr[n-1]) + countSubsetSum(arr, n-1, sum);
    }
    else{
        return countSubsetSum(arr, n-1, sum);
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    cout << countSubsetSum(arr, n, sum);
}