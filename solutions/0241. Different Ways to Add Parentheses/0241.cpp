class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> memo;
    return ways(input, memo);
  }

 private:
  vector<int> ways(const string& s, unordered_map<string, vector<int>>& memo) {
    if (memo.count(s))
      return memo[s];

    vector<int> ans;

    for (int i = 0; i < s.length(); ++i)
      if (ispunct(s[i]))
        for (const int a : ways(s.substr(0, i), memo))
          for (const int b : ways(s.substr(i + 1), memo))
            if (s[i] == '+')
              ans.push_back(a + b);
            else if (s[i] == '-')
              ans.push_back(a - b);
            else
              ans.push_back(a * b);

    if (ans.empty())  // single number
      return memo[s] = {stoi(s)};
    return memo[s] = ans;
  }
};
