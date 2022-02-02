#include<bits/stdc++.h>
using namespace std;

int coinChange(int *coin, int n, int s, int **t){
    for(int i = 0; i < n + 1; i++){
        t[i][0] = 0;
    }
    for(int j = 0; j < s + 1; j++){
        t[0][j] = 0;
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < s + 1; j++){
            if(coin[i-1] <= j){
                t[i][j] = 1 + min(t[i][j-coin[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = 1 + t[i-1][j];
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
    int **t = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        t[i] = new int[s + 1];
    }
    cout << coinChange(coin, n, s, t) << endl;
    return 0;
}