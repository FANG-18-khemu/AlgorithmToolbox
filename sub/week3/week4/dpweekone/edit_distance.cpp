#include <iostream>
#include <string>
#include <vector>
using namespace std;
int min(int a, int b, int c)
{
  return (a <= b && a <= c) ? a : (b <= a && b <= c) ? b : c;
}
int edit_distance(const string &str1, const string &str2)
{
  int str1_len = str1.length();
  int str2_len = str2.length();
  vector<vector<int> > dp(str1_len + 1, vector<int>(str2_len + 1, 0));
  for (int i = 0; i <= str1_len; i++)
  {
    dp[i][0] = i;
  }
  for (int i = 0; i <= str2_len; i++)
  {
    dp[0][i] = i;
  }
  for (int i = 1; i <= str1_len; i++)
  {
    for (int j = 1; j <= str2_len; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]);
      }
      else
      {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
      }
    }
  }
  return dp[str1_len][str2_len];
}

int main()
{
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
