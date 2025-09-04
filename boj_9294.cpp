#include<bits/stdc++.h>

using namespace std;

int N,M,S,T;
vector<int> v;

void solve(int n){
    if(n == N){
        int res = 0;
        for(int k : v) res += k;
        if(res == S){
            cout << "(";
            for(int i = 0;i<N-1;i++) cout << v[i] << ",";
            cout << v[N-1] << ")\n";
        }
        return;
    }
    int tmp = 1;
    if(n != 0) tmp = v.back(); 
    for(;tmp<=M;tmp++){
        v.push_back(tmp);
        solve(n+1);
        v.pop_back();
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for(int i = 1;i<=T;i++){
        cin >> N >> M >> S;
        cout << "Case " << i << ":\n";
        solve(0);
    }
}