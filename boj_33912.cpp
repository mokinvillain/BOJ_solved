#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,arr[101010],ans,ans2,M;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1;i<=N;i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for(int i = 1;i<M;i++){
        if(ans%N > arr[i]){
            ans -= ans%N;
            ans += N + arr[i];
        }
        else{
            ans -= ans%N;
            ans += arr[i];
        }
    }
    for(int i = N;i>=M;i--){
        if(ans2%N > arr[i]){
            ans2 -= ans2%N;
            ans2 += N + arr[i];
        }
        else{
            ans2 -= ans2%N;
            ans2 += arr[i];
        }
    }
    if(ans > ans2) cout << "CCW";
    else if(ans == ans2) cout << "EQ";
    else cout << "CW";
}