#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, tam;
    long num;
    bool ver;
    deque<int> screen;
    set<int> elements;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>num;
        //tela cheia e elemento nao esta nela
        if(elements.count((num)) == 0){
            ver = true;
        }
        if(screen.size() == k && ver){
            elements.erase(screen.front());
            screen.pop_front();
            screen.push_back(num);
            elements.insert(num);

            //tela vazia ou tela com vaga sobrando e elemento não está nela
        } else if(screen.empty() || (screen.size() < k && ver)){
            screen.push_back(num);
            elements.insert(num);
        }
        ver = false;
    }
    tam = screen.size();
    cout<<tam<<endl;
    for(int j =0; j<tam; j++){
        cout<<screen.back()<<" ";
        screen.pop_back();
    }


    return 0;
}