#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N,M,DP[201010];
string str1,str2;

vector<int> GetFail(const string &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

vector<int> KMP(const string &s, const string &p){
    int n = s.size(), m = p.size();
    vector<int> fail = GetFail(p), ret;
    for(int i=0, j=0; i<s.size(); i++){
        while(j && s[i] != p[j]) j = fail[j-1];
            if(s[i] == p[j]){
            if(j == m) j = fail[j];
            else j++;
        }
        ret.push_back(j);
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio();
    cin >> N >> M; 
    cin >> str1 >> str2;
    vector<int> arr = KMP(str2,str1);
    for(int i = 1;i<=M;i++){
        DP[i] = DP[i-1] + 1;
        if(arr[i-1] == N) DP[i] = min(DP[i],DP[i-N]);
        if(i <= M-N) DP[i] = min(DP[i],DP[i-arr[i-1]] + N - arr[i-1]);
        cout << DP[i] << " ";
    }
}