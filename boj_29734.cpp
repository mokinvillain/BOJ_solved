#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,M,T,S;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> T >> S;
    

    if(N%8 == 0){
        N += (N/8)*S;
        N -= S;
    }
    else{
        N += (N/8)*(S);
    }
    if(M%8 == 0){
        M += (M/8)*(S+T*2);
        M -= S+T*2;
        M += T;
    }
    else{
        M += (M/8)*(S+T*2);
        M += T;
    }
    if(M < N){
        cout << "Dok\n" << M;
    }
    else cout << "Zip\n" << N;
}