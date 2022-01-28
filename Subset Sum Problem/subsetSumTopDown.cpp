#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *arr, int n, int sum, int **t){
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
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(arr[i - 1] <= j){
                t[i][j] = (t[i-1][j-arr[i-1]]|| t[i-1][j]);
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
    cout << subsetSum(val, n, sum, t) << endl;
    return 0;
}