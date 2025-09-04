#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,G,B,D,nxt[50101],ans;
pll arr[50101];
stack<pll> s;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> G >> B >> D;
    for(int i = 1;i<=N;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr+1,arr+N+1);
    s.push({arr[N].second,N});
    nxt[N] = -1;
    for(int i = N-1;i>=1;i--){
        while(!s.empty() && arr[i].second < s.top().first) s.pop();
        if(s.empty()) nxt[i] = -1;
        else nxt[i] = s.top().second;
        s.push({arr[i].second,i});
    }
    for(int i = 1;i<N;i++){
        B -= arr[i].first;
        cout << B << " ";
        if(B < 0){
            cout << -1;
            return 0;
        }
        if(nxt[i] == -1 || arr[nxt[i]].first-arr[i].first > G){
            ans += (G-B)*arr[i].second;
            B = G + arr[i].first;
        }
        else{
            ans += (arr[nxt[i]].first-arr[i].first-B)*arr[i].second;
            B = arr[nxt[i]].first;
            i = nxt[i] - 1;
        }
    }
    if(D - arr[N].first > G){
        cout << -1;
        return 0;
    }
    else if(B >= )
    cout << ans;
}