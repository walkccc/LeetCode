class Solution {
 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    if (n == 1)
      return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> ans;

    if (k == 0) {
      for (char c = '1'; c <= '9'; ++c)
        ans.push_back(stoi(string(n, c)));
      return ans;
    }

    for (int num = 1; num <= 9; ++num)
      dfs(n - 1, k, num, ans);

    return ans;
  }

 private:
  void dfs(int n, int k, int num, vector<int>& ans) {
    if (n == 0) {
      ans.push_back(num);
      return;
    }

    const int lastDigit = num % 10;

    for (const int nextDigit : {lastDigit - k, lastDigit + k})
      if (0 <= nextDigit && nextDigit <= 9)
        dfs(n - 1, k, num * 10 + nextDigit, ans);
  }
};
