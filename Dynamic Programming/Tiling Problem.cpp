#include <bits/stdc++.h>
#define forloop(i,s,e) for(int i=s; i<e; i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*

Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.
Input Format

First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.
Constraints

1 <= T<= 1000
1 <= N,M <= 100000
Output Format

Print answer for every test case in a new line modulo 10^9+7.
Sample Input

2
2 3
4 4

Sample Output

1
2

*/

const int mod = 1e9+7;
ll dp[100005];

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n,m;
    cin >> n >> m;
    if(n < m) {
      cout << 1 << endl;
      continue;
    }
    if(n == m) {
      cout << 2 << endl;
      continue;
    }
    for(int i = 1; i < m; i++)
      dp[i] = 1;
    dp[m] = 2;
    for(int i = m+1; i <= n; i++) {
      dp[i] = (dp[i-1] + dp[i-m]) % mod;
    }
    cout << dp[n]<< endl;
  }
  return 0;
}