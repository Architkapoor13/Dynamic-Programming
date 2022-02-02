#include<bits/stdc++.h>
using namespace std;

int coinChange(int *coin, int n, int s){
    if(n == 0|| s==0){
        return 0;
    }
    if(coin[n-1] <= s){
        return 1 + min(coinChange(coin, n, s-coin[n-1]), coinChange(coin, n-1, s));
    }
    else{
        return 1 + coinChange(coin, n-1, s);
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
    cout << coinChange(coin, n, s) << endl;
    return 0;
}