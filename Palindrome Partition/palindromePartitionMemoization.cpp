#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}


int minNumberOfPartions(string s, int i, int j, int **t){
    if(i >= j || isPalindrome(s, i, j)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = minNumberOfPartions(s, i, k, t) + minNumberOfPartions(s, k + 1, j,t) + 1;
        ans = min(temp, ans);
    }
    return t[i][j] = ans;
}

int main(){
    string s;
    cin >> s;
    int **t = new int*[s.size() + 1];
    for(int i = 0; i < s.size() + 1; i++){
        t[i] = new int[s.size() + 1];
    }
    for(int i = 0; i < s.size() + 1; i++){
        for(int j = 0; j < s.size() + 1; j++){
            t[i][j] = -1;
        }
    }

    cout << minNumberOfPartions(s, 0, s.size() - 1, t);
    return 0;
}