#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long tam1, tam2, num, count = 0, cases, temp;
    cin >> cases;
    while (cases--) {
        cin >> tam1, cin >> tam2;
        map<int, int> c1, c2;
        set<int> nums;
        for (int i = 0; i < tam1; i++) {
            cin >> num;
            c1[num]++;
            nums.insert(num);
        }
        for (int i = 0; i < tam2; i++) {
            cin >> num;
            c2[num]++;
            nums.insert(num);
        }

            count=0;
            for(set<int>::iterator it=nums.begin(); it!=nums.end(); it++){
                temp =  abs(c1[*it] - c2[*it]);
                count += temp;
            }
            cout<<count<<endl;
}

    return 0;
}