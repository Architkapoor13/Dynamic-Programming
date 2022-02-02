#include<bits/stdc++.h>
using namespace std;

int coinChange(int *coin, int n, int s, int **t){
    if(n == 0){
        return t[n][s] = 0;
    }
    if(s == 0){
        return t[n][s] = 1;
    }
    if(t[n][s] != -1){
        return t[n][s];
    }
    if(coin[n-1] <= s){
        return t[n][s] =  coinChange(coin, n, s-coin[n-1], t) + coinChange(coin, n-1, s, t);
    }
    else{
        return t[n][s] =  coinChange(coin, n-1, s, t);
    }
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