#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cases,tam, menordif = 9999999, dif = 0;
    cin>>cases;
    while(cases>0){
        cin>>tam;
        vector<int> v(tam);
        for(int i =0; i<tam; i++) cin>>v[i];

        //sort
        for (int j = 1; j < tam; j++){
            for(int i = 0; i < tam-1; i++){
                if (v[i] < v[i+1]){
                    swap(v[i], v[i+1]);
                }
            }
        }

        for(int i =0; i<tam-1; i++){
                dif = v[i] - v[i + 1];
            if(dif<menordif){
                menordif=dif;
            }
        }

        cout<<menordif<<endl;
        menordif=9999999;
        cases--;
    }


    return 0;
}