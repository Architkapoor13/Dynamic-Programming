#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr, int n, int sum, int **t){
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(j == 0){
                t[i][j]=1;
            }
            else if(i == 0){
                t[i][j]=0;
            }
            else{
                t[i][j] = -1;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(arr[i-1] <= sum){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
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
    cout << countSubsetSum(arr, n, sum, t);
}