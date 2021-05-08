#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int memo[200][20], garments[20][20], numberg[20], cases, m, types;

int shop(int money, int atual) {
	if (money < 0){
        return -1e6;
	}
	if (atual == types){
        return m - money;
	}

	if (memo[money][atual] != -1){
        return memo[money][atual];
	}

	int resp = -1e6;
	for (int i = 0; i < numberg[atual]; i++) {
		resp = max(resp, shop(money - garments[atual][i], atual+1));
	}
	return memo[money][atual] = resp;
}

int main() {
	cin>>cases;
	while (cases--){
		cin>>m>>types;
		for (int i = 0; i < types; i++) {
			cin>>numberg[i];
			for (int j = 0; j < numberg[i]; j++) {
				cin>>garments[i][j];
			}
		}

		memset(memo, -1, 200 * 20 * 4);
		int resp = shop(m, 0);
		if (resp > 0){
            cout<<resp<<endl;
		}else{
            cout<<"no solution"<<endl;
		}

	}
	return 0;
}