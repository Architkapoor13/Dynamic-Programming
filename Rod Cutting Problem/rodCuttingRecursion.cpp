#include<bits/stdc++.h>
using namespace std;

int rodCutting(int *length, int *price, int size, int N){
    if(size == 0 || N == 0){
        return 0;
    }
    if(length[size-1] <= N){
        return max(price[size-1] + rodCutting(length, price, size, N-length[size-1]), rodCutting(length, price, size-1, N));
    }
    else{
        return rodCutting(length, price, size-1, N);
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
    cout << rodCutting(length, price, n, rodLength) << endl;
    return 0;
}