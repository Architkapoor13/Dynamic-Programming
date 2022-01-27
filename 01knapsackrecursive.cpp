#include<bits/stdc++.h>
using namespace std;

int knapSack(int *wt, int *val, int w, int n){
    if(n == 0 || w == 0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1] + knapSack(wt, val, w - wt[n-1], n - 1), knapSack(wt, val, w, n - 1));
    }
    else{
        return knapSack(wt, val, w, n-1);
    }
}

int main(){
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    int w;
    cin >> w;
    cout << knapSack(wt, val, w, n) << endl;
    return 0;
}