class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    return count_if(begin(words), end(words),
                    [&](const auto& word) { return word.find(pref) == 0; });
  }
};
