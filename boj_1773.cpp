#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,C,arr[111],ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> C;
    for(int i = 0;i<N;i++) cin >> arr[i];
    for(int i = 1;i<=C;i++){
        for(int j = 0;j<N;j++){
            if(i%arr[j] == 0){
                ans++;
                break;
            }
        }
    }
    cout << ans;
}