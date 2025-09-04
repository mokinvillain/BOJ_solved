#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 101010;
ll N,M,K;

struct Trie{
    map<char,Trie*> ch;
    void insert(const string &v,int idx = 0){
        if(idx == v.size()){
           return;
        }
        auto it = ch.find(v[idx]);
        if(it == ch.end()) it = ch.emplace(v[idx],new Trie()).first;
        it->second->insert(v,idx+1);
    }
    bool check(const string &v,int idx = 0){
        if(idx == v.size()) return 1;
        auto it = ch.find(v[idx]);
        if(it == ch.end()) return 0;
        return it->second->check(v,idx+1);
    }
};

Trie T;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string str;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> str;
        T.insert(str);
    }
    for(int i = 0;i<M;i++){
        cin >> str;
        if(T.check(str)) K++;
    }
    cout << K;
}