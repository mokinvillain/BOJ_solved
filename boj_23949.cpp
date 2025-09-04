#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,A_DP[1 << 20],H,T,arr[21][2],B_DP[1 << 20];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for(int tc = 1;tc<=T;tc++){
        cin >> N >> H;
        ll tmp = (1 << N) - 1;
        for(int i = 0;i<N;i++) cin >> arr[i][0];
        for(int i = 0;i<N;i++) cin >> arr[i][1];
        for(int i = 0;i<(1 << N);i++){
            A_DP[i] = 0;
            ll res = 0;
            for(int j = 0;j<N;j++){
                if((i | (1 << j)) == i) res += arr[j][0];
            }
            if(res >= H) A_DP[i] = 1;
        }
        for(int i = 0;i < N;i++){
            for(int mask = 0; mask < (1<<N);mask++){
                if(mask & (1<<i)) A_DP[mask] += A_DP[mask^(1<<i)];
            }
        }
        for(int i = 0;i<(1 << N);i++){
            B_DP[i] = 0;
            ll res = 0;
            for(int j = 0;j<N;j++){
                if((i | (1 << j)) == i) res += arr[j][1];
            }
            if(res >= H) B_DP[i] = A_DP[i];
        }
        for(int i = 0;i < N;i++){
            for(int mask = 0; mask < (1<<N);mask++){
                if(mask & (1<<i)) B_DP[mask] += B_DP[mask^(1<<i)];
            }
        }
        cout << "Case #" << tc << ": " << B_DP[(1 << N)-1] << "\n";
    }
}