#include<bits/stdc++.h>
using namespace std;

int coinChange(int *coin, int n, int s, int **t){
    // INT_MAX-1 because INT_MAX + 1 = INT_MIN
    for(int i = 0; i < s + 1; i++){
        t[0][i] = INT_MAX - 1;
    }
    for(int i = 0; i < n+1; i++){
        t[i][0] = 1;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < s + 1; j++){
            if(coin[i-1] <= j){
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][s];
}

int main(){
    int n;
    cin >> n;
    int *coin = new int[n];
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    int s;
    cin >> s;
    int **t =  new int *[n + 1];
    for(int i = 0; i < n+1; i++){
        t[i] = new int[s + 1];
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < s + 1; j++){
            t[i][j] = -1;
        }
    }
    cout << coinChange(coin, n, s, t) << endl;
    return 0;
}