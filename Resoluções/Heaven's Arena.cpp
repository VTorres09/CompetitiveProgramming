#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    float floor, matches, prob, ans;
    cin>>floor>>matches>>prob;
    ans = (((prob/100)*matches)-((100-prob)/100)*matches);
    cout << setprecision(6) << fixed;
    cout <<floor+ans<<"000";
    return 0;
}
