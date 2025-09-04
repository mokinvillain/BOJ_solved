#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A,B,K,ans;
vector<ll> prime;
unordered_map<ll,ll> DP[60];
set<ll> ls;

bool IsPrime(ll n){
    if(n < 2) return false;
    for(ll i=2; i*i<=n; i++) if(n % i == 0) return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> A >> B >> K;
    for(ll i = A;i<=B;i++){
        if(IsPrime(i)) prime.push_back(i);
    }
    DP[0][0] = 1;
    ls.insert(0);
    for(int i = 1;i<=prime.size();i++){
        for(auto j : DP[i-1]){
            DP[i][j.first+prime[i-1]] += DP[i-1][j.first];
            DP[i][j.first] += DP[i-1][j.first];
        }
    }
    cout << DP[prime.size()][K];
}