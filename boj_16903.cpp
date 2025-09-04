#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r,cnt, res;
    Node() : l(-1), r(-1), cnt(0), res(-1) {}
};

Node node[6060606];
queue<int> q;

int root;
int arr[30];

int new_Node(){
    int ret = q.front();
    q.pop();
    return ret;
}

void insert(int x){
    int now = root, v = x;
    for(int i = 29;i>=0;i--){
        arr[i] = (x & 1);
        x >>= 1;
    }
    for(int i = 0;i<30;i++){
        if(!arr[i]){
            if(node[now].l == -1) node[now].l = new_Node();
            now = node[now].l;
            node[now].cnt++;
            if(i == 29) node[now].res = v;
        }
        else{
            if(node[now].r == -1) node[now].r = new_Node();
            now = node[now].r;
            node[now].cnt++;
            if(i == 29) node[now].res = v;
        }
    }
}

void erase(int x){
    int now = root, v = x;
    for(int i = 29;i>=0;i--){
        arr[i] = (x & 1);
        x >>= 1;
    }
    for(int i = 0;i<30;i++){
        if(!arr[i]){
            int nxt = node[now].l;
            if(--node[nxt].cnt == 0){
                node[now].l = -1;
                node[nxt].res = -1;
                q.push(nxt);
            }
            now = nxt;
        }
        else{
            int nxt = node[now].r;
            if(--node[nxt].cnt == 0){
                node[now].r = -1;
                node[nxt].res = -1;
                q.push(nxt);
            }
            now = nxt;
        }
    }
}

int query(int x){
    int now = root, v = x;
    for(int i = 29;i>=0;i--){
        arr[i] = (x & 1);
        x >>= 1;
    }
    for(int i = 0;i<=30;i++){
        if(node[now].res != -1) return (v ^ node[now].res);
        if(arr[i]){
            if(node[now].l != -1) now = node[now].l;
            else now = node[now].r;
        }
        else{
            if(node[now].r != -1) now = node[now].r;
            else now = node[now].l;
        }
        if(node[now].res != -1) return v ^ node[now].res;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1;i<6060606;i++) q.push(i);
    root = new_Node();
    insert(0);
    int Q,cmd,X;
    cin >> Q;
    while(Q--){
        cin >> cmd >> X;
        if(cmd == 1) insert(X);
        else if(cmd == 2) erase(X);
        else cout << query(X) << "\n";
    }
}