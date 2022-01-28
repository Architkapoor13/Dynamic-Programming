#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *arr, int n, int sum){
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(arr[n-1] <= sum){
        return (subsetSum(arr, n-1, sum - arr[n-1]) || subsetSum(arr, n-1, sum));
    }
    else{
        return subsetSum(arr, n-1, sum);
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
    cout << subsetSum(val, n, sum) << endl;
    return 0;
}