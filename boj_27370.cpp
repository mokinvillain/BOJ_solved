#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T,N,a,b,arr[101010],totA,totB;
vector<ll> res;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        totA = totB = 0;
        res.clear();
        cin >> N >> a >> b;
        for(int i = 0;i<N;i++) cin >> arr[i];
        for(int i = 0;i<N;i++){
            if(abs(a - arr[i]) == abs(b - arr[i])) res.push_back(abs(a - arr[i]));
            else if(abs(a - arr[i]) > abs(b - arr[i])) totB += abs(b-arr[i])*2;
            else totA += abs(a-arr[i])*2;
        }
        for(ll i : res){
            if(totA > totB) totB += i*2;
            else totA += i*2;
        }
        cout << totA + totB << " " << abs(totA - totB) << "\n";
    }
}