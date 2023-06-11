class Solution {
 public:
  int countPrefixes(vector<string>& words, string s) {
    return count_if(begin(words), end(words),
                    [&](const string& word) { return s.find(word) == 0; });
  }
};
