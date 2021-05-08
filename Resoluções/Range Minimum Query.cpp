#include<iostream>
typedef long long ll;
using namespace std;
const int N = 100010;
int v[N], tree[4*N];

void build(int p, int l, int r){
    if(l==r){
        tree[p] = v[r];
    }else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        build(lc, l, m);
        build(rc, m+1, r);
        tree[p] = min(tree[lc], tree[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(ql<=l && r <=qr){
        return tree[p];
    }else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        if(qr<=m){
            return query(lc,l,m,ql,qr);
        }else if(ql>m){
            return query(rc, m+1, r, ql, qr);
        }else{
            return min(query(lc,l,m,ql,qr),query(rc, m+1, r, ql, qr));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, queries, ql, qr; cin>>n;
    for(int i = 0; i<n; i++) cin>>v[i];
    build(1,0,n-1);
    cin>>queries;
    for(int i = 0; i<queries; i++){
        cin>>ql>>qr;
        cout<<query(1,0,n-1,ql,qr)<<endl;
    }
}