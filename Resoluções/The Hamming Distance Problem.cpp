#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases; cin>>cases;
    long long n, h;
    while (cases--){
        cin>>n>>h;
        vector<int> subset(n, 0);
        for(int i=0; i<h; i++){
            subset[i] = 1;
        }
        reverse(subset.begin(), subset.end());
        do{
            for(int i = 0; i<subset.size(); i++){
                cout<< subset[i];
            }
            cout<<endl;
        }while (next_permutation(subset.begin(), subset.end()));

        if(cases>0){
            cout<<"\n";
        }
    }
    return 0;
}