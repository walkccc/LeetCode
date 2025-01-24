class Solution {
 public:
  bool isPossibleToRearrange(string s, string t, int k) {
    const int n = s.length();
    return getCount(s, n / k) == getCount(t, n / k);
  }

 private:
  unordered_map<string, int> getCount(const string& s, int sz) {
    unordered_map<string, int> count;
    for (int i = 0; i < s.length(); i += sz)
      ++count[s.substr(i, sz)];
    return count;
  };
};
