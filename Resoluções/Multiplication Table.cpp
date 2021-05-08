#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
ll table[1010][1010], a[1010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>table[i][j];
        }
    }

    a[1]=sqrt(table[1][2]*table[1][3]/table[2][3]);
    cout<<a[1]<<' ';
    for(int i=1;i<n;i++){
        a[i+1]=table[i][i+1]/a[i];
        cout<<a[i+1]<<' ';
    }

    return 0;
}



