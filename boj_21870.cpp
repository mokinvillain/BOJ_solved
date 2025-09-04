#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[201010],N;

ll gcd(ll a,ll b){
    if(a%b == 0) return b;
    return gcd(b,a%b);
}

ll back(ll s,ll e){
    if(s == e) return arr[s];
    int m =(e-s+1)/2 + s - 1;
    ll t1 = arr[s], t2 = arr[m+1];
    for(int i = s;i<=m;i++) t1 = gcd(t1,arr[i]);
    for(int i = m+1;i<=e;i++) t2 = gcd(t2,arr[i]);
    t1 += back(m+1,e);
    t2 += back(s,m);
    return max(t1,t2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> arr[i];
    cout << back(1,N);
}