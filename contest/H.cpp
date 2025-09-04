#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

void solve(ll a, ll b){ // a가 더 큼
    ll x=0;
    for(int bit=63; bit>=0; bit--){
        if((a & (1LL<<bit)) == (b & (1LL<<bit))){
            x |= (a & (1LL<<bit));
        }
        else{
            //cout<<bit<<' ';
            if(x == 0){
                x |= (a & (1LL<<bit));
            }
            else if(x != b){
                x |= (a & (1LL<<bit));
            }
            break;
        }
    }
    
    int ans=0;
    //cout<<x<<'?';
    
    while(x != 1){
        if(x%2==0) x/=2;
        else{x=(x+1)/2; ans++;};
    }
    cout<<ans<<'\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        ll a, b; cin>>a>>b;
        solve(b, a);
    }
}