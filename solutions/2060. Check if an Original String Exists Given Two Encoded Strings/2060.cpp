class Solution {
 public:
  bool possiblyEquals(string s1, string s2) {
    dp.resize(s1.length() + 1,
              vector<unordered_map<int, bool>>(s2.length() + 1));
    return f(s1, s2, 0, 0, 0);
  }

 private:
  vector<vector<unordered_map<int, bool>>> dp;

  // Returns true if s1[i..n) matches s2[j..n) with the padding difference.
  // `paddingDiff` := signed padding, if positive, s1 has a positive number of
  // offset bytes relative to s2
  bool f(const string& s1, const string& s2, int i, int j, int paddingDiff) {
    if (const auto it = dp[i][j].find(paddingDiff); it != dp[i][j].cend())
      return it->second;
    if (i == s1.length() && j == s2.length())
      return paddingDiff == 0;
    if (i < s1.length() && isdigit(s1[i])) {
      // Add padding on s1.
      const int nextLetterIndex = getNextLetterIndex(s1, i);
      for (const int num : getNums(s1.substr(i, nextLetterIndex - i)))
        if (f(s1, s2, nextLetterIndex, j, paddingDiff + num))
          return true;
    } else if (j < s2.length() && isdigit(s2[j])) {
      // Add padding on s2.
      const int nextLetterIndex = getNextLetterIndex(s2, j);
      for (const int num : getNums(s2.substr(j, nextLetterIndex - j)))
        if (f(s1, s2, i, nextLetterIndex, paddingDiff - num))
          return true;
    } else if (paddingDiff > 0) {
      // `s1` has more padding, so j needs to catch up.
      if (j < s2.length())
        return f(s1, s2, i, j + 1, paddingDiff - 1);
    } else if (paddingDiff < 0) {
      // `s2` has more padding, so i needs to catch up.
      if (i < s1.length())
        return f(s1, s2, i + 1, j, paddingDiff + 1);
    } else {  // paddingDiff == 0
      // There's no padding difference, so consume the next letter.
      if (i < s1.length() && j < s2.length() && s1[i] == s2[j])
        return f(s1, s2, i + 1, j + 1, 0);
    }
    return dp[i][j][paddingDiff] = false;
  }

  int getNextLetterIndex(const string& s, int i) {
    int j = i;
    while (i < s.length() && isdigit(s[j]))
      ++j;
    return j;
  }

  vector<int> getNums(const string& s) {
    vector<int> nums{stoi(s)};
    if (s.length() == 2) {
      nums.push_back(stoi(s.substr(0, 1)) + stoi(s.substr(1, 1)));
    } else if (s.length() == 3) {
      nums.push_back(stoi(s.substr(0, 1)) + stoi(s.substr(1, 2)));
      nums.push_back(stoi(s.substr(0, 2)) + stoi(s.substr(2, 1)));
      nums.push_back(stoi(s.substr(0, 1)) + stoi(s.substr(1, 1)) +
                     stoi(s.substr(2, 1)));
    }
    return nums;
  }
};
