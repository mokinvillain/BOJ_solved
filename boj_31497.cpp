#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N;
bool check[555][2];
string arr[555];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++) cin >> arr[i];
    for(int i = 0;i<N;i++){
        bool check1,check2;
        cout << "? " << arr[i] << "\n";
        cout << flush;
        cin >> check[i][0];
        cout << "? " << arr[i] << "\n";
        cout << flush;
        cin >> check[i][1];
    }
    for(int i = 0;i<N;i++){
        if(check[i][0] && check[i][1]){
            cout << "! " << arr[i] << "\n";
            cout << flush;
            return 0;
        }
    }
    for(int i = 0;i<N;i++){
        if(check[i][0] || check[i][1]){
            cout << "! " << arr[i] << "\n";
            cout << flush;
            return 0;
        }
    }
}