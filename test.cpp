#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e5,MOD = 1e9 + 7;

ll T,N,sum,K;
vector<ll> sieve,nxt;

int main(){
    cin >> N;
    cout << "? ";
    for(int i = 0;i<N;i++){
        cout << i%6 << " ";
        sum += (i%6)*9;
    }
    cout << "\n";
    cout << flush;
    cin >> K;
    sum = K - sum;
    for(int i = 0;i<N;i++){
        if(i%6 == sum) sieve.push_back(i+1); 
    }
    sum = 0;
    cout << "? ";
    ll cur = 0;
    for(int i = 0;i<N;i++){
        if(cur == sieve.size() || i != sieve[cur] - 1) cout << "0 ";
        else{
            cout << cur%6 << " ";
            sum += (cur%6)*9;
            cur++;
        }
    }
    cout << "\n";
    cout << flush;
    cin >> K;
    sum = K - sum;
    for(int i = 0;i<sieve.size();i++){
        if(i%6 == sum) nxt.push_back(sieve[i]);
    }
    sieve.clear();
    for(int i : nxt) sieve.push_back(i);
    sum = 0;
    cout << "? ";
    cur = 0;
    for(int i = 0;i<N;i++){
        if(cur == sieve.size() || i != sieve[cur] - 1) cout << "0 ";
        else{
            cout << cur%6 << " ";
            sum += (cur%6)*9;
            cur++;
        }
    }
    cout << "\n";
    cout << flush;
    cin >> K;
    sum = K - sum;
    nxt.clear();
    for(int i = 0;i<sieve.size();i++){
        if(i%6 == sum) nxt.push_back(sieve[i]);
    }
    cout << "! ";
    cout << nxt[0] << "\n";
    cout << flush;
}