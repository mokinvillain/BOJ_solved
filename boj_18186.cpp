#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 1010101;
ll N,M,K,arr[SZ],ans,tmp,B,C;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> B >> C;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    if(B <= C){
        for(int i = 1;i<=N;i++) tmp += arr[i];
        cout << tmp*B;
        return 0;
    }
    for(int i = 1;i<=N-2;i++){
        if(arr[i+1] > arr[i+2]){
            tmp = INT_MAX;
            tmp = min(arr[i],arr[i+1] - arr[i+2]);
            ans += tmp*(B+C);
            for(int j = 0;j<2;j++) arr[i+j] -= tmp;
            tmp = INT_MAX;
            for(int j = 0;j<3;j++) tmp = min(tmp,arr[i+j]);
            ans += tmp*(B+2*C);
            for(int j = 0;j<3;j++) arr[i+j] -= tmp;
            ans += arr[i]*B;
        }
        else{
            tmp = INT_MAX;
            for(int j = 0;j<3;j++) tmp = min(tmp,arr[i+j]);
            ans += tmp*(B+2*C);
            for(int j = 0;j<3;j++) arr[i+j] -= tmp;
            tmp = INT_MAX;
            for(int j = 0;j<2;j++) tmp = min(tmp,arr[i+j]);
            ans += tmp*(B+C);
            for(int j = 0;j<2;j++) arr[i+j] -= tmp;
            ans += arr[i]*B;
        }
    }
    tmp = INT_MAX;
    for(int j = 0;j<2;j++) tmp = min(tmp,arr[N-1+j]);
    ans += tmp*(B+C);
    for(int j = 0;j<2;j++) arr[N-1+j] -= tmp;
    ans += arr[N-1]*B;
    ans += arr[N]*B;
    cout << ans;
}