#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 10007;
vector<ll> v[52];
ll N,M,H,DP[51][1010],tmp;
string str;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> H;
    cin.ignore();
    for(int i = 1;i<=N;i++){
        getline(cin,str);
        tmp = 0;
        for(int k = 0;k<str.size();k++){
            if(str[k] == ' '){
                v[i].push_back(tmp);
                tmp = 0;
            }
            else{
                tmp *= 10;
                tmp += str[k] - '0';
            }
        }
        v[i].push_back(tmp);
    }
    DP[0][0] = 1;
    for(int i = 1;i<=N;i++){
        for(int k = 0;k<=1000;k++) DP[i][k] = DP[i-1][k];
        for(int j : v[i]){
            for(int k = 0;k<=1000;k++){
                if(k >= j){
                    DP[i][k] += DP[i-1][k-j];
                    DP[i][k] %= MOD;
                }
            }
        }
    }
    cout << DP[N][H];
}