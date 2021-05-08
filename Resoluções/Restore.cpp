#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    long long n, num, sumT, sumL;
    cin>>n;
    sumT=0;
    sumL=0;
    long long matrix[n][n];
    long long sumLines[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
            sumT+= matrix[i][j];
            sumL+= matrix[i][j];
        }
        sumLines[i] = sumL;
        sumL=0;
    }
    sumT = sumT/(n-1);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] ==0){
                cout<<sumT-sumLines[i]<<" ";
            } else {
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;

    }


    return 0;
}
 