#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int *val, int *wt, int n, int w){
    if(n == 0 || w == 0){
        return 0;
    }
    if(wt[n-1] <= w){
        return max(val[n-1] + unboundedKnapsack(val, val, n, w-wt[n-1]), unboundedKnapsack(val, val, n-1, w));
    }
    else{
        return unboundedKnapsack(val, wt, n-1, w);
    }
}

int main(){
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];
    for(int i = 0; i < n ; i++){
        cin >> wt[i] >> val[i];
    }
    int w;
    cin >> w;
    cout << unboundedKnapsack(val, wt, n, w) << endl;
    return 0;

}