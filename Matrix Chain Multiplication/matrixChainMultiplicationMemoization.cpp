#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int *arr, int i, int j, int **t){
    if(i >= j){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int minAns = INT_MAX;
    for(int k = i; k < j; k++){
        int temp1 = matrixChainMultiplication(arr, i, k, t);
        int temp2 = matrixChainMultiplication(arr, k + 1, j, t);
        int calc = arr[i-1] * arr[k] * arr[j];
        minAns = min(minAns, temp1 + temp2 + calc);
    }
    return t[i][j] = minAns;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int **t = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        t[i] = new int[n + 1];
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            t[i][j] = -1;
        }
    }
    cout << matrixChainMultiplication(arr, 1, n-1, t);
    return 0;

}