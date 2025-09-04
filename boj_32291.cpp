#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N; 
vector<ll> arr;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N; 
    arr.push_back(1);
    for(ll i = 2;i*i<=N;i++){
        if((N+1)%i == 0){
            arr.push_back(i);
            arr.push_back((N+1)/i);
        }
    }
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    for(ll i : arr) cout << i << " ";
}