#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> conjunto;
    int tam, num, count = 0; cin>>tam;
    for(int i=0; i<tam; i++){
        cin>>num;
        if(conjunto.count(num)==0){
            conjunto.insert(num);
        } else {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
 }