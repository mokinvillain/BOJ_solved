#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,arr[501010],ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    ans += arr[N];
    for(int i = N-1;i>=1;i--){
        if(arr[i+1] < arr[i]){
            arr[i] = arr[i+1];
            ans += arr[i];
        }
        else ans += arr[i];
    }
    cout << ans;
}