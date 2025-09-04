#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

vector<string> s;
string str;

bool cmp(const string &u,const string &v){
    string p = u+v,k = v+u;
    for(int i = 0;i<p.size();i++){
        if(p[i] > k[i]) return 1;
        if(k[i] > p[i]) return 0;
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(cin >> str) s.push_back(str);
    sort(s.begin(),s.end(),cmp);
    for(string i : s) cout << i;
}