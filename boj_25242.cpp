#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N,Q,tmp;
unordered_map<string,vector<string>> m;
unordered_map<string,ll> dist;
vector<string> train[101010];
string str,start_point,end_point;

void bfs(){
    if(dist[start_point] != 0) return;
    queue<string> q;
    q.push(start_point);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        for(string next_stop : m[cur]){
            if(dist[next_stop] != 0 || next_stop == start_point) continue;
            dist[next_stop] = dist[cur] + 2;
            q.push(next_stop);
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 0;i<N;i++){
        cin >> tmp;
        while(tmp--){
            cin >> str;
            train[i].push_back(str);
        }
        for(int j = 0;j<train[i].size()-1;j++){
            m[train[i][j]].push_back(train[i][j+1]);
            m[train[i][j+1]].push_back(train[i][j]);
        }
    }
    while(Q--){
        cin >> start_point >> end_point;
        bfs();
        cout << dist[end_point] << " " << dist[start_point] << "\n";
        if(dist[end_point] == 0) cout << "-1\n";
        else cout << dist[end_point] - dist[start_point] << "\n";
    }
}