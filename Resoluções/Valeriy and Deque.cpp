#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, q, elements, a, b,  maximo = -1;
    long long operation;
    vector<int> res;
    deque<int> d;
    vector<pair<int, int>> dupla;

    cin>>n>>q;
    //preenchendo deque
    for(int i=0; i<n; i++){
        cin>>elements;
        maximo=max(elements,maximo);
        d.push_back(elements);
    }

    while(d.front()!=maximo) {
        //Retirando elementos da frente
        a = d.front();
        d.pop_front();
        b = d.front();
        d.pop_front();
        //Colocando duplas no vetor
        dupla.emplace_back(a, b);
        //Realocando elementos retirados
        if (a > b) {
            d.push_front(a);
            d.push_back(b);
        } else {
            d.push_front(b);
            d.push_back(a);
        }
    }

    //Retirando elemento maximo
    d.pop_front();

    //Colocando elementos restantes no array e esvaziando a deque
    int count = 0;
    while (!d.empty()){
        res.push_back(d.front());
        d.pop_front();
        count++;
    }

    while (q--){
        cin >> operation;
        //Printando resultados
        if (operation <= dupla.size()){
            cout << dupla[operation-1].first << ' ' << dupla[operation-1].second << endl;
        }else{
            operation -= dupla.size();
            operation-=1;
            cout << maximo << ' ' << res[operation%(count)] << endl;
        }
    }

    return 0;
}