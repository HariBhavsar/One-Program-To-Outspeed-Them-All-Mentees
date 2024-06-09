#include <iostream>
#include <algorithm>
#include <chrono>
#define Loop(i,a,b) for (int i = a ; i < b ; i++)
#define MOD 1000000007
typedef long long int ll;
using namespace std;
using namespace chrono;
/*
    * INTRO :
    * After seeing the Fibonacci example most of you must have thought it is quite easy to come up with a way to minimise
    * the number of recursive calls to a function. 
    * The easiest way to do that would of course be to do it iteratively where f(n) = f(n - 1) + f(n - 2) and the results
    * could be stored in just two additional variables.
    * However in more general cases, we would be needing the results of various subproblems that are not exactly pertaining
    * to n - 1 or n - 2.
    * Here you will be able to appreciate the speedup due to memoization 
    
    * THE PROBLEM:
    * Consider a money system consisting of n coins. Each coin has a positive integer value. 
      Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
      For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
        2+2+5
        2+5+2
        5+2+2
        3+3+3
        2+2+2+3
        2+2+3+2
        2+3+2+2
        3+2+2+2
    * Input:
        The first input line has two integers n and x: the number of coins and the desired sum of money.
        The second line has n distinct integers c1,c2,...,c_n: the value of each coin.
    * Output
        Print one integer: the number of ways modulo 10^9+7.
    Example
        Input:
        3 9
        2 3 5
    Output:
        8
    * From CSES/Dynamic_Programming/Coin_Combinations_1
    * This file has a recursive non memoized solution and is quite slow.
    * TASK:
    * Implement a memoized version of the same algorithm. 
    * You have to only fill in the function solutuion_M(ll* coins, int n, ll sum).
*/
ll Count_R = 0;
ll Count_M = 0;
ll* dp;
ll solution_R(ll* coins, int n, ll sum){
    Count_R++;
    if (sum == 0) return 1;
    ll N = 0;
    Loop(i,0,n){
        if (sum - coins[i] < 0) break;
        N = (N + solution_R(coins,n,sum - coins[i]))%MOD;
    }
    return N;
}
ll solution_M(ll* coins, int n, ll sum){
    Count_M++; // Do not remove this line
    ll N = 0;
    // STUDENT CODE BEGINS HERE
    cout<<"STUDENT CODE NOT IMPLEMENTED\n";
    exit(1);
    return N;
}
int main(int argc, char* argv[]){
    int choice = atoi(argv[1]);
    int n;
    ll x;
    cin >> n >> x;
    ll* coins = new ll[n];
    Loop(i,0,n) cin >> coins[i];
    sort(coins,coins + n);
    if (choice == 1){
        auto start_R = high_resolution_clock::now();
        ll N_R = solution_R(coins,n,x);
        auto end_R = high_resolution_clock::now();
        cout << N_R << "\n";
        auto elapsed_R = duration_cast<duration<double>>(end_R - start_R);
        cout << "Time spent " << elapsed_R.count() << "\n";
        cout << "Number of recursive calls " << Count_R << "\n";
    }
    else if (choice == 2){
        dp = new ll[x + 1];
        auto start_M = high_resolution_clock::now();
        ll N_M = solution_M(coins,n,x);
        auto end_M = high_resolution_clock::now();
        cout << N_M << "\n";
        auto elapsed_M = duration_cast<duration<double>>(end_M - start_M);
        cout << "Time spent " << elapsed_M.count() << "\n";
        cout << "Number of recursive calls " << Count_M << "\n";
        delete [] dp;
    }
    else if (choice == 3){
        dp = new ll[x + 1];
        auto start_R = high_resolution_clock::now();
        ll N_R = solution_R(coins,n,x);
        auto end_R = high_resolution_clock::now();
        auto elapsed_R = duration_cast<duration<double>>(end_R - start_R);
        auto start_M = high_resolution_clock::now();
        ll N_M = solution_M(coins,n,x);
        auto end_M = high_resolution_clock::now();
        auto elapsed_M = duration_cast<duration<double>>(end_M - start_M);
        cout << "\t\t\t Recursion \t" << "Memoization\n";
        cout << "Time spent \t\t" << elapsed_R.count() << "\t" << elapsed_M.count() << "\n";
        cout << "Number of recurive calls " << Count_R << "\t\t" << Count_M << "\n";
        cout << "Answer \t\t\t" << N_R << "\t\t" << N_M << "\n";
        delete [] dp;
    }
    cout << "\n";
    delete [] coins;
    return 0;
}