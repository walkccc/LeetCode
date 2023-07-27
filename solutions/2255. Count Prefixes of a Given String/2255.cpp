class Solution {
 public:
  int countPrefixes(vector<string>& words, string s) {
    return count_if(words.begin(), words.end(),
                    [&](const string& word) { return s.find(word) == 0; });
  }
};
