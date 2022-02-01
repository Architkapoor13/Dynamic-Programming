#include<bits/stdc++.h>
using namespace std;

int rodCutting(int *length, int *price, int size, int N){
    int **t = new int*[size+1];
    for(int i = 0; i < N + 1; i++){
        t[i] = new int[N + 1];
    }
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < N + 1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
            else{
                t[i][j] = -1;
            }
        }
    }
    for(int i = 1; i < size+1; i++){
        for(int j = 1; j < N + 1; j++){
            if(length[i-1] <= j){
                t[i][j] = max(price[i-1] + t[i][j - length[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[size][N];
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
    cout << rodCutting(length, price, n, rodLength) << endl;
    return 0;
}