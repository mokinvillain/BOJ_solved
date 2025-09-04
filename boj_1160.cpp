#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
ll M,A,C,X0,N,g;

ll mulMOD(ll a,ll b,ll c){
    return (__int128_t)a*b%c;
}

ll pow(ll a,ll b,ll c){
    ll res = 1;
    for(a%=c; b; b>>=1,a=mulMOD(a,a,c)) if(b&1) res = mulMOD(res,a,c);
    return res;
}

matrix MUL(matrix A, matrix B){
    matrix res(A.size(),vector<ll>(B.size(),0));
    for(ll i = 0;i<A.size();i++){
        for(ll j = 0;j<A[i].size();j++){
            for(int k = 0;k<B.size();k++){
                res[i][j] += mulMOD(A[i][k],B[k][j],M);
                res[i][j] %= M;
            }
        }
    }
    return res;
}

matrix solve(ll c,matrix fd){
    if(c == 1) return fd;
    matrix res = solve(c/2,fd);
    if(c%2 == 1){
        res = MUL(res,res);
        res = MUL(res,fd);
        return res;
    }
    else return MUL(res,res);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> M >> A >> C >> X0 >> N >> g;
    matrix fd = {{A,C},{0,1}},res = {{X0},{1}};
    matrix ans = solve(N,fd);
    ans = MUL(ans,res);
    cout << ans[0][0]%g;
}