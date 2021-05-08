#include<iostream>
#include<map>
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
        //soma
        tree[p] = tree[lc]*tree[rc];
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
            return query(lc,l,m,ql,qr)*query(rc, m+1, r, ql, qr);
        }
    }
}

void update(int p, int l, int r, int i, int x){
    if(l == r){
        tree[p] = v[i] = x;
    }else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        if(i<=m){
            update(lc, l, m, i,x );
        }else{
            update(rc, m+1, r, i, x);
        }
        tree[p] = tree[lc]*tree[rc];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, num;
    while(cin>>n>>k) {
        for (int i = 1; i <= n; i++) {
            cin >> num;
            if (num > 0) v[i] = 1;
            else if (num < 0) v[i] = -1;
            else v[i] = 0;
        }
        build(1, 1, n);
        for (int i = 0; i < k; i++) {
            char comando;
            cin >> comando;
            if (comando == 'C') {
                int i, v;
                cin >> i >> v;
                if (v > 0) update(1, 1, n, i, 1);
                else if (v < 0) update(1, 1, n, i, -1);
                else update(1, 1, n, i, 0);

            } else if (comando == 'P') {
                int i, j, ret;
                cin >> i >> j;
                ret = query(1, 1, n, i, j);
                if (ret > 0) cout << "+";
                else if (ret < 0) cout << "-";
                else cout << "0";
            }
        }

        cout<<endl;
    }
    return 0;
}