#include <bits/stdc++.h>
#define forloop(i,s,e) for(int i=s; i<e; i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*

You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.
Input Format

First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.
Constraints

1<=t<=100 1<=n<=90
Output Format

Print the number of all possible binary strings.
Sample Input

2
2
3

Sample Output

3
5

Explanation

1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

*/

const int mod = 1e9+7;
ll dp[92];

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // freopen("error.txt", "w", stderr);
  #endif


  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    dp[1] = 2;
    dp[2] = 3;

    forloop(i,3,n+1)
      dp[i] = dp[i-1] + dp[i-2];

    cout << dp[n] << endl;
  }
  return 0;
}