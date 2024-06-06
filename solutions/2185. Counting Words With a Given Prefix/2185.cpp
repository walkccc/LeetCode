class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    return ranges::count_if(
        words, [&](const string& word) { return word.find(pref) == 0; });
  }
};
