#include<iostream>
using namespace std;
int seq(string X, string Y, int m, int n){
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i < m+1; i++){
        for (j = 0; j < n+1; j++){
            if (i == 0 || j == 0){
                L[i][j] = 0;
            }else if (X[i - 1] == Y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
            }else{
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    return L[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    while(getline(cin, a) and getline(cin,  b)){
        cout<<seq(a, b, a.size(), b.size())<<endl;
    }

    return 0;
}