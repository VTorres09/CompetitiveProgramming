#include <iostream>
#include <deque>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cases, n, num, alice, bob, last, moves, total;
    bool key; //ESQUERDA = FALSE, DIREITA = TRUE
    deque <int> candies;
    cin >> cases;
    while(cases>0){
        cin>>n;
        alice = 0;
        bob = 0;
        for(int i=0; i<n; i++){
            cin>>num;
            candies.push_back(num);
        }


        last=0;
        moves=0;
        total = 0;
        key=true;
        while(candies.size()>0){

            if(key){
                //ESQUERDA
                while(true){
                    total += candies.front();
                    alice+= candies.front();
                    candies.pop_front();
                    if(total>last || candies.size()==0){
                        break;
                    }
                }
                last = total;
                total = 0;
                moves++;
                key=false;
            } else {
                //DIREITA
                while(true){
                    total += candies.back();
                    bob+= candies.back();
                    candies.pop_back();
                    if(total>last || candies.size()==0){
                        break;
                    }
                }
                last = total;
                total = 0;
                moves++;
                key=true;
            }

        }


        cout << moves << " " << alice << " " << bob <<endl;
        candies.clear();
        cases--;
    }
    return 0;
}