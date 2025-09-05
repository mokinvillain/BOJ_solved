#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll T,N,tmp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> N;
        ll sum = 0;
        for(int i = 0;i<N;i++){
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << "\n";
    }
}