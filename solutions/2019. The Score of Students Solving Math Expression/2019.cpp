class Solution {
 public:
  int scoreOfStudents(string s, vector<int>& answers) {
    const int n = s.length() / 2 + 1;
    const unordered_map<char, function<int(int, int)>> func{
        {'+', plus<int>()}, {'*', multiplies<int>()}};
    int ans = 0;
    vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(n));
    unordered_map<int, int> count;

    for (int i = 0; i < n; ++i)
      dp[i][i].insert(s[i * 2] - '0');

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        for (int k = i; k < j; ++k) {
          const char op = s[k * 2 + 1];
          for (const int a : dp[i][k])
            for (const int b : dp[k + 1][j]) {
              const int res = func.at(op)(a, b);
              if (res <= 1000)
                dp[i][j].insert(res);
            }
        }
      }

    const int correctAnswer = eval(s);

    for (const int answer : answers)
      ++count[answer];

    for (const auto& [answer, freq] : count)
      if (answer == correctAnswer)
        ans += 5 * freq;
      else if (dp[0][n - 1].count(answer))
        ans += 2 * freq;

    return ans;
  }

 private:
  int eval(const string& s) {
    int ans = 0;
    int prevNum = 0;
    int currNum = 0;
    char op = '+';

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c))
        currNum = currNum * 10 + (c - '0');
      if (!isdigit(c) || i == s.length() - 1) {
        if (op == '+') {
          ans += prevNum;
          prevNum = currNum;
        } else if (op == '*') {
          prevNum = prevNum * currNum;
        }
        op = c;
        currNum = 0;
      }
    }

    return ans + prevNum;
  }
};
