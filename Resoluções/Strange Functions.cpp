#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cases;
    string num;
    cin >> cases;
    while(cases>0){
        cin>>num;
        cout<<num.length()<<endl;
        cases--;
    }
    return 0;
}
