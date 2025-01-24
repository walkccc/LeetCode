class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty())
      return {};

    const int k = words.size();
    const int n = words[0].length();
    vector<int> ans;
    unordered_map<string, int> count;

    for (const string& word : words)
      ++count[word];

    for (int i = 0; i < s.length() - k * n + 1; ++i) {
      unordered_map<string, int> seen;
      int j;
      for (j = 0; j < k; ++j) {
        const string& word = s.substr(i + j * n, n);
        if (++seen[word] > count[word])
          break;
      }
      if (j == k)
        ans.push_back(i);
    }

    return ans;
  }
};
