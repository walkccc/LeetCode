class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    string ans;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    while (true) {
      const bool addOne = !ans.empty() && shouldAddOne(ans, count);
      const int i = getLargestChar(ans, count);
      if (i == -1)
        break;
      const int repeats = addOne ? 1 : min(count[i], repeatLimit);
      ans += string(repeats, 'a' + i);
      count[i] -= repeats;
    }

    return ans;
  }

 private:
  bool shouldAddOne(const string& ans, const vector<int>& count) {
    for (int i = 25; i >= 0; --i)
      if (count[i])
        return ans.back() == 'a' + i;
    return false;
  }

  int getLargestChar(const string& ans, const vector<int>& count) {
    for (int i = 25; i >= 0; --i)
      if (count[i] && (ans.empty() || ans.back() != 'a' + i))
        return i;
    return -1;
  }
};
