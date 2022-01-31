#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int *val, int *wt, int n, int w){
    int **t = new int*[n+1];
    for(int i = 0; i < n + 1; i++){
        t[i] = new int[w + 1];
    }
    for(int i = 0; i < n + 1; i++){
        t[i][0] = 0;
    }
    for(int i = 0; i < w + 1; i++){
        t[0][i] = 0;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < w + 1; j++){
            t[i][j] = t[i-1][j];
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            }
        }
    }
    return t[n][w];
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