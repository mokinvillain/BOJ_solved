#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,arr[301010],arr2[301010],res;
string str = "";

string trans(ll x){
    string res = "";
    while(x != 0){
        if(x%2 == 1) res.push_back('1');
        else res.push_back('0');
        x >>= 1;
    }
    while(res.size() < 34) res.push_back('0');
    reverse(res.begin(),res.end());
    return res;
}

ll trans2(string x){
    ll res = 0;
    for(int i = 0;i<x.size();i++){
        if(x[i] == '1') res += pow(2,(x.size() - i));
    }
    return res;
}

struct Trie{
    map<char,Trie*> ch;
    int cnt = 0;
    void insert(const string &v,int idx = 0){
        cnt++;
        if(idx == v.size()){
           return;
        }
        auto it = ch.find(v[idx]);
        if(it == ch.end()) it = ch.emplace(v[idx],new Trie()).first;
        it->second->insert(v,idx+1);
    }
    void del(const string &v,int idx = 0){
        cnt--;
        if(idx == v.size()){
           return;
        }
        auto it = ch.find(v[idx]);
        if(it == ch.end()) return;
        it->second->del(v,idx+1);
    }
    string check(string &cur){
        if(ch.size() == 0) return cur;
        auto it = ch.find('1');
        if(it == ch.end() || cnt == 0) it = ch.find('0');
        for(auto i : ch) cout << i.first << " " << i.second->cnt << " ";
        cout << "\n";
        if(it == ch.find('1')) cur.push_back('1');
        else cur.push_back('0');
        return it->second->check(cur);
    }
};

Trie T;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> arr[i];
        res ^= arr[i];
    }
    for(int i = 0;i<N;i++){
        cin >> arr2[i];
        res ^= arr2[i];
    }
    for(int i = 0;i<N;i++){
        T.insert(trans(arr[i]^res));
    }
    for(int i = 0;i<N;i++) T.del(trans(arr[i]^res));
    string p = T.check(str);
    cout << p << "\n";
    cout << trans2(p);
}