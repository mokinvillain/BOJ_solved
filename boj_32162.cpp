#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,tmp = 1,T;
vector<ll> arr;
unordered_map<ll,bool> check;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    for(int i = 1;i<=200000;i++){
        if(i%3 == 0 || i%5 == 5){
            continue;
        }
        arr.push_back(i);
    }
    while(T--){
        cin >> N;
        cout << arr[N-1] << "\n";
    }
}