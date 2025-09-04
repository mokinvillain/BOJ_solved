#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
unordered_map<ll,bool> check;
ll N,M,sum[101010],tmp1 = 1,tmp2;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 1;i<=M;i++){
        tmp2++;
        tmp1 *= N;
        tmp1 %= MOD;
        sum[i] += sum[i-1];
        if(!check[tmp2]){
            check[tmp2] = 1;
            sum[i] += tmp2;
        }
        if(!check[tmp1]){
            check[tmp1] = 1;
            sum[i] += tmp1;
        }
        cout << tmp1 << " " << tmp2 << "\n";
        cout << sum[i] << "\n";
    }
}