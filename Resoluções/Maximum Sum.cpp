#include<iostream>
using namespace std;
int input[105][105];

int kadane(int arr[], int &start, int &end, int n) {
    int sum = 0, maxSum = INT_MIN;
    end = -1;
    int tempStart = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            tempStart = i+1;
        }else if (sum > maxSum) {
            maxSum = sum;
            start = tempStart;
            end = i;
        }
    }

    if (end != -1)
        return maxSum;

    maxSum = arr[0];
    start = end = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            start = end = i;
        }
    }
    return maxSum;
}

void maxSum(int n) {
    int maxSum = INT_MIN;

    int left, right;
    int temp[n], sum, start, end;

    for (left = 0; left < n; left++) {
        for(int i = 0; i<n; i++)
            temp[i] = 0;

        for (right = left; right < n; ++right) {
            for (int i = 0; i < n; ++i)
                temp[i] += input[i][right];
            sum = kadane(temp, start, end, n);

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    cout << maxSum;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }

    maxSum(n);
    return 0;
}