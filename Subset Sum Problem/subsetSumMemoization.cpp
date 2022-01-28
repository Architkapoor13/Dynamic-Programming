#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *arr, int n, int sum, int **t){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(t[n][sum] != -1){
        return t[n][sum];
    }
    if(arr[n-1] <= sum){
        return t[n][sum] = (subsetSum(arr, n-1, sum-arr[n-1], t) || subsetSum(arr, n-1, sum, t));
    }
    else{
        return t[n][sum] = subsetSum(arr, n-1, sum, t);
    }
}

int main(){
    int n;
    cin >> n;
    int *val = new int[n];
    for(int  i = 0; i < n; i++){
        cin >> val[i];
    }
    int sum;
    cin >> sum;
    int **t = new int*[n + 1];
    for(int i = 0 ;i < n + 1; i++){
        t[i] = new int [sum+1];
    }
    for(int i = 0; i < sum + 1; i++){
        t[0][i] = false;

    }
    for(int i = 0; i < n + 1; i++){
        t[i][0] = true;
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0 && j == 0){
                t[i][j] = 1;
            }
            else if(j == 0){
                t[i][j] = 1;
            }
            else if(i == 0){
                t[i][j] = 0;
            }
            t[i][j] = -1;
        }
    }
    cout << subsetSum(val, n, sum, t) << endl;
    return 0;
}