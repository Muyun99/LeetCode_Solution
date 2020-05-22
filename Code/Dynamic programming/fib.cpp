#include<iostream>
#include<string>
#include<vector>
using namespace std;

int fib1(int N) {
    if (N == 1 || N == 2) 
        return 1;
    return fib1(N - 1) + fib1(N - 2);
}

int helper(vector<int>& memo, int n){
    if(n == 1 || n == 2)
        return 1;
    else if(memo[n] != 0)
        return memo[n];
    else
        memo[n] = helper(memo, n-1) + helper(memo, n-2);
        return memo[n];
}

int fib2(int N){
    if(N < 1)
        return 0;
    vector<int> memo(N+1, 0);
    return helper(memo, N);   
}

int fib3(int N){
    if(N < 1)
        return 0;
    if(N == 1 || N == 2)
        return 1;
    vector<int> dptable(N+1,0);
    dptable[0] = 0;
    dptable[1] = 1;
    for(int i = 2;i <= N;i++)
        dptable[i] = dptable[i-1] + dptable[i-2];
    return dptable[N];
}

int main(){
    cout << fib1(10) << endl;
    cout << fib2(10) << endl;
    cout << fib3(10) << endl;
    return 0;
}