#include<iostream>
using namespace std;
int memo[105][105];

int permutations(int n, int k){

    if (n == 0){
        return 0;
    }
    if (k == 0){
        return 1;
    }

    if (memo[n][k] != 0){
        return memo[n][k];
    }
    int sum = 0;
    for (int i = 0; i <= k; i++){
        if (i <= n - 1){
            sum += permutations(n - 1,k - i);
        }
    }
    memo[n][k] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases; cin>>cases;
    while(cases--){
        int n, m; cin>>n>>m;
        cout<<permutations(n,m)<<endl;
    }

}