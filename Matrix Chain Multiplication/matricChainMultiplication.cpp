#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int *arr, int i, int j){
    if(i >= j){
        return 0;
    }
    int minAns = INT_MAX;
    for(int k = i; k < j; k++){
        int temp1 = matrixChainMultiplication(arr, i, k);
        int temp2 = matrixChainMultiplication(arr, k + 1, j);
        int calc = arr[i-1] * arr[k] * arr[j];
        minAns = min(minAns, temp1 + temp2 + calc);
    }
    return minAns;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << matrixChainMultiplication(arr, 1, n-1);
    return 0;

}