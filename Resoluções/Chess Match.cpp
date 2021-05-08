#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int players, minderrotas;
    bool wint1 = true, wint2 =true;
    cin>>players;
    vector<int> t1(players);
    vector<int> t2(players);
    //Recebendo entrada
    for(int i=0; i<players; i++){
        cin>>t1[i];
    }
    for(int j=0; j<players; j++){
        cin>>t2[j];
    }
    sort (t1.begin(), t1.end());
    sort (t2.begin(), t2.end());

    if(players % 2==1){
        minderrotas=players/2;
    } else{
        minderrotas=(players/2)-1;
    }
        for(int k=0, j=players; k<(players-minderrotas); k++, j--){
            if(t1[players-k-1] < t2[j-minderrotas-1]){
                wint1 = false;
            }
            if (t2[players-k-1] < t1[j-minderrotas-1]){
                wint2 = false;
            }

        }
        if(wint1&&wint2){
            cout<<"Both"<<endl;
        } else if(wint1&&!wint2){
            cout<<"First"<<endl;
        } else if(wint2&&!wint1){
            cout<<"Second"<<endl;
        } else{
            cout<<"None"<<endl;
        }

    return 0;
}
