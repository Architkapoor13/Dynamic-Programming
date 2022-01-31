#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int *val, int *wt, int n, int w, int **t){
    if(n == 0 || w == 0){
        return t[n][w] = 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(wt[n-1] <= w){
        return t[n][w] = max(val[n-1]+unboundedKnapsack(val, wt, n, w-wt[n-1], t), unboundedKnapsack(val, wt, n-1, w, t));
    }
    else{
        return t[n][w] = unboundedKnapsack(val, wt, n-1, w, t);
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
    int **t = new int*[n+1];
    for(int i = 0; i < n + 1; i++){
        t[i] = new int[w + 1];
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < w + 1; j++){
            t[i][j] = -1;
        }
    }
    cout << unboundedKnapsack(val, wt, n, w, t) << endl;
    return 0;

}