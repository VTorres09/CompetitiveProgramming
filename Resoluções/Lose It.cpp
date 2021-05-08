#include <iostream>
using namespace std;

int matching(int x){
    if(x == 4){
        return 0;
    }else if(x==8){
        return 1;
    }else if(x==15){
        return 2;
    }else if(x==16){
        return 3;
    }else if(x==23){
        return 4;
    }else if(x==42){
        return 5;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int tam, num;
    int resp[6] = {0};
    cin>>tam;
    for(int i=0; i<tam; i++){
        cin>>num;
        if(matching(num) == 0){
            resp[matching(num)]++;
        } else if(resp[matching(num)-1]>0){
            resp[matching(num)-1]--;
            resp[matching(num)]++;
        }
    }
    cout << tam-6*resp[5]<<endl;
    return 0;
}