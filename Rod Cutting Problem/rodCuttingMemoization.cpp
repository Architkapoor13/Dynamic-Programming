#include<bits/stdc++.h>
using namespace std;

int rodCutting(int *length, int *price, int size, int N, int **t){
    if(size == 0 || N == 0){
        return t[size][N] = 0;
    }
    if(t[size][N] != -1){
        return t[size][N];
    }
    if(length[size-1] <= N){
        return t[size][N] = max(price[size-1] + rodCutting(length, price, size, N-length[size-1], t), rodCutting(length, price, size-1, N, t));
    }
    else{
        return t[size][N] = rodCutting(length, price, size-1, N, t);
    }
}


int main(){
    int n;
    cin >> n;
    int *price = new int[n];
    int *length = new int[n];
    for(int i = 0; i < n; i++){
        cin >> price[i];
        length[i] = i+1;
    }
    int rodLength;
    cin >> rodLength;
    int **t = new int*[n+1];
    for(int i = 0; i < n + 1; i++){
        t[i] = new int[rodLength + 1];
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < rodLength + 1; j++){
                t[i][j] = -1;
        }
    }
    cout << rodCutting(length, price, n, rodLength, t) << endl;
    return 0;
}