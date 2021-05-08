#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll books, minutes, num;
    vector<ll> bm;
    cin>>books>>minutes;
    for(ll i =0; i<books; i++){
        cin>>num;
        bm.push_back(num);
    }

    ll l  = 0, i = 0, max = 0, sum = 0, b = 0;
    while(l != books) {
        if(sum + bm[l] <= minutes) {
            b++;
            sum += bm[l++];
            if(b > max){
                max = b;
            }
        }else {
            b--;
            sum -= bm[i++];
        }
    }

    cout << max << endl;
    return 0;
}
