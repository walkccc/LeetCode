class Solution {
 public:
  int countPrefixes(vector<string>& words, string s) {
    return ranges::count_if(
        words, [&](const string& word) { return s.find(word) == 0; });
  }
};
