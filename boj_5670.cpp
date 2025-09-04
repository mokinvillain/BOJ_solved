#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

double ans;

struct Trie{
    map<char,Trie> ch;
    int cnt = 0;
    void insert(const string &v,int idx = 0){
        if(idx == v.size()) return;
        auto it = ch.find(v[idx]);
        if(it == ch.end()) it = ch.emplace(v[idx],Trie()).first;
        it->second.cnt++;
        it->second.insert(v,idx+1);
    }
    void solve(int size){
        if(size != this->cnt) ans += this->cnt;
        for(auto &[s,nxt] : ch){
            nxt.solve(this->cnt);
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll N;
    cout << fixed;
    cout.precision(2);
    while(cin >> N){
        Trie T;
        string str;
        ans = 0;
        for(int i = 0;i<N;i++){
            cin >> str;
            T.insert(str);
        }
        T.solve(-1);
        cout << ans/N << "\n";
    }
}