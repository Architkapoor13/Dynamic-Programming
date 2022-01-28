#include<bits/stdc++.h>
using namespace std;

bool equalSumPartition(int *arr, int n, int sum, int **t){
    if(sum == 0){
        return true;
    }
    if(n ==0){
        return false;
    }
    if(t[n][sum] != -1){
        return t[n][sum];
    }
    if(arr[n - 1] <= sum ){
        return t[n][sum] = (equalSumPartition(arr, n-1, sum-arr[n-1], t) || equalSumPartition(arr, n-1, sum, t));
    }
    else{
        return t[n][sum] = equalSumPartition(arr, n-1, sum, t);
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
    int **t = new int*[n+1];
    for(int i = 0; i < n + 1; i++){
        t[i] = new int[(sum / 2) + 1];
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0 &&j == 0){
                t[i][j] = 1;
            }
            else if(j == 0){
                t[i][j] = 1;
            }
            else if(i == 0){
                t[i][j] = 0;
            }
            else{
                t[i][j] = -1;
            }
        }
    }
    if(sum % 2 != 0){
        cout << "Not able to split!" << endl;
    }
    else{
        if(equalSumPartition(arr, n, sum/2, t)){
            cout << "Able to split!" << endl;
        }
    }
}