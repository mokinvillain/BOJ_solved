#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T,N,arr[5050],arr2[5050];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1;i<=N;i++) cin >> arr[i];
        for(int i = 1;i<=N;i++) cin >> arr2[i];
        sort(arr+1,arr+N+1);
        sort(arr2+1,arr2+N+1);
        for(int i = 1;i<=N;i++) cout << arr[i] << " ";
        cout << "\n";
        for(int i = 1;i<=N;i++) cout << arr2[i] << " ";
        cout << "\n";
    }
}