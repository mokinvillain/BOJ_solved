#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T,M,cnt,tmp,K;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> M;
        cnt = 1;
        priority_queue<ll> max_heap;
        priority_queue<ll,vector<ll>,greater<>> min_heap;
        cout << M/2 + 1 << "\n";
        cin >> tmp;
        max_heap.push(tmp);
        cout << tmp << " ";
        for(int i = 2;i<=M;i++){
            cin >> K;
            if(K >= max_heap.top()) min_heap.push(K);
            else max_heap.push(K);
            if(min_heap.size() > max_heap.size()){
                tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
            }
            if(max_heap.size() == min_heap.size() + 2){
                tmp = max_heap.top();
                max_heap.pop();
                min_heap.push(tmp);
            }
            if(i%2 == 1){
                cout << max_heap.top() << " ";
                cnt++;
                if(cnt%10 == 0) cout << "\n";
            }
        }
        cout << "\n";
    }
}