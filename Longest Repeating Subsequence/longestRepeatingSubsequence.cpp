#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubs(string s){
    string a = s;
    string b = s;
    int m = a.size();
    int n = b.size();
    int **t = new int*[m + 1];
    for(int i = 0; i < m + 1; i++){
        t[i] = new int[n + 1];
    }
    for(int i = 0; i < n + 1; i++){
        t[0][i] = 0;
    }
    for(int i = 0; i < m + 1; i++){
        t[i][0] = 0;
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(a[i-1] == b[j-1] && i != j){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return  t[m][n];
}

int main(){
    string a;
    cin >> a;
    cout << longestRepeatingSubs(a) << endl;
    return 0;

}