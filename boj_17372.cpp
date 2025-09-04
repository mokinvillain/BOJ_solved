#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef vector<vector<ll>> matrix;
const ll MAX = 1000000;

unordered_map<ll,ll> DP;
unordered_map<ll,matrix> memo;
ll phi[1010101],cnt;
const ll MOD = 1000000007;
matrix fd = {{1,1},{1,0}};

ll mulMOD(ll a,ll b,ll c){
    return (__int128_t)a*b%c;
}


void phi_Sieve(){
    for(ll i = 1;i<=MAX;i++){
        phi[i] += i;
        for(ll j = 2;j*i<=MAX;j++) phi[j*i] -= phi[i];
        phi[i] += phi[i-1];
    }
}

matrix MUL(matrix A, matrix B){
    matrix res(A.size(),vector<ll>(B.size(),0));
    for(ll i = 0;i<A.size();i++){
        for(ll j = 0;j<A[i].size();j++){
            for(int k = 0;k<B.size();k++){
                res[i][j] += mulMOD(A[i][k],B[k][j],MOD);
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

matrix solve(ll C){
    if(C == 1) return fd;
    if(memo.find(C) != memo.end()) return memo[C];
    matrix res = solve(C/2);
    if(C%2 == 1){
        res = MUL(res,res);
        res = MUL(res,fd);
        return memo[C] = res;
    }
    else return memo[C] = MUL(res,res);
}

ll S(ll x){
    if(x <= MAX) return phi[x];
    if(DP.find(x) != DP.end()) return DP[x];
    ll i,j;
    ll res = x*(x+1ll)/2;
    for(i = 2;i<=x;i=j+1){
        j = x/(x/i);
        res -= (j-i+1)*S(x/i);
    }
    return DP[x] = res;
}

ll P(ll n){
    ll i,j;
    ll ans = 0;
    for(i = 1;i<=n;i=j+1){
        j = n/(n/i);
        matrix tmp1 = solve(j+2),tmp2 = solve(i+1);
        ans += mulMOD((tmp1[1][0] - tmp2[1][0]),((S(n/i)*2) - 1),MOD);
        ans %= MOD;
        ans = (ans + MOD)%MOD;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll N;
    cin >> N;
    phi_Sieve();
    cout << P(N) << "\n";
}