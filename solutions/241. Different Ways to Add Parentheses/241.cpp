class Solution {
 public:
  vector<int> diffWaysToCompute(string expression) {
    return ways(expression, {});
  }

 private:
  vector<int> ways(const string& s, unordered_map<string, vector<int>>&& mem) {
    if (const auto it = mem.find(s); it != mem.cend())
      return it->second;

    vector<int> ans;

    for (int i = 0; i < s.length(); ++i)
      if (ispunct(s[i]))
        for (const int a : ways(s.substr(0, i), std::move(mem)))
          for (const int b : ways(s.substr(i + 1), std::move(mem)))
            if (s[i] == '+')
              ans.push_back(a + b);
            else if (s[i] == '-')
              ans.push_back(a - b);
            else
              ans.push_back(a * b);

    return mem[s] = (ans.empty() ? vector<int>{stoi(s)} : ans);
  }
};
