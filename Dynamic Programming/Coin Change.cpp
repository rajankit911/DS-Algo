#include <bits/stdc++.h>
#define forloop(i,s,e) for(int i=s; i<e; i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, In how many ways can we make the change? The order of coins doesn’t matter.
Input Format

First line of input contain two space separated integers N and M. Second line of input contains M space separated integers - value of coins.
Constraints

1<=N<=250 1<=m<=50 1 <= Si <= 50
Output Format

Output a single integer denoting the number of ways to make the given change using given coin denominations.
Sample Input

10 4
2 5 3 6

Sample Output

5



*/


const int mod = 1e9+7;
int dp[252];

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // freopen("error.txt", "w", stderr);
  #endif

  int n,m;
  cin >> n >> m;

  int denomination[m];

  forloop(i,0,m)
    cin >> denomination[i];

  dp[0] = 1;
  forloop(i,0,m) {
    forloop(j,1,n+1) {
      if(j-denomination[i] < 0) continue;

      dp[j] += dp[j-denomination[i]];
    }
  }

  cout << dp[n];
  return 0;
}