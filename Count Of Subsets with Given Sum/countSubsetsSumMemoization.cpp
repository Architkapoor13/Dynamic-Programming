#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr, int n, int sum, int **t){
    if(sum == 0){
        return t[n][sum] = 1;
    }
    if(n == 0){
        return t[n][sum] = 0;
    }
    if(t[n][sum] != -1){
        return t[n][sum];
    }
    if(arr[n-1] <= sum){
        return t[n][sum] = countSubsetSum(arr, n-1, sum-arr[n-1], t) + countSubsetSum(arr, n-1, sum, t);
    }
    else{
        return t[n][sum] = countSubsetSum(arr, n-1, sum, t);
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
    int **t;
    t = new int*[n + 1];
    for(int i = 0; i < n+1; i++){
        t[i] = new int[sum + 1];
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            t[i][j] = -1;
        }
    }
    cout << countSubsetSum(arr, n, sum, t);
}