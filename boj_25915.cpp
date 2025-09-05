#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

char st;
string yun = "ILOVEYONSEI";
ll N;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> st;
    for(int i = 0;i<yun.size();i++){
        N += abs(st - yun[i]);
        st = yun[i];
    }
    cout << N;
}