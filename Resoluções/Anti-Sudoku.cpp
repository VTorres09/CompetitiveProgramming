#include <iostream>
#include <string>
using namespace std;


int prox(int num) {
    int res;
    if (num != 57) {
        res = num + 1;
    } else {
        res = 49;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cases;
    string sudoku[9];
    cin>>cases;
    while(cases>0){
        for(int i=0; i<9; i++){
                cin>>sudoku[i];
        }

        sudoku[0].at(0) =  prox(sudoku[0].at(0));
        sudoku[1].at(3) = prox(sudoku[1].at(3));
        sudoku[2].at(6) = prox(sudoku[2].at(6));
        sudoku[3].at(1) = prox(sudoku[3].at(1));
        sudoku[4].at(4) = prox(sudoku[4].at(4));
        sudoku[5].at(7) = prox(sudoku[5].at(7));
        sudoku[6].at(2) = prox(sudoku[6].at(2));
        sudoku[7].at(5) = prox(sudoku[7].at(5));
        sudoku[8].at(8) = prox(sudoku[8].at(8));

        for(int i=0; i<9; i++){
            cout<<sudoku[i]<<endl;
        }

        cases--;
    }

    return 0;
}
