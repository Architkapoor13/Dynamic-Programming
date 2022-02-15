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

int minNumberOfPartitions(string s, int i, int j){
    if( i >= j ||isPalindrome(s, i,j)){
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = minNumberOfPartitions(s, i, k) + minNumberOfPartitions(s, k + 1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << minNumberOfPartitions(s, 0, s.size() - 1);
    return 0;
}