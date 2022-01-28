#include<bits/stdc++.h>
using namespace std;

bool equalSumPartition(int *arr, int n, int sum){
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
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = (t[i-1][j - arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
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