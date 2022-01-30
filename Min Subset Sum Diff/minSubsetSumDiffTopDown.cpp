#include<bits/stdc++.h>
using namespace std;

int** subsetSum(int *arr, int n, int sum){
    int **t = new int*[n+1];
    for(int i=0;i<n+1;i++){
        t[i] = new int[sum + 1];
    }
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++){
            if(i == 0){
                t[i][j] = 0;
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int **t = subsetSum(arr, n, sum);
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum + 1; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    int s1 = INT_MAX;
    for(int i = 0; i <= sum/2; i++){
        if(t[n][i]){
            s1 = min(sum-2*i, s1);
        }
    }
    cout << s1 << endl;
    return 0;
}