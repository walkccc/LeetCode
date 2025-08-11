class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    return accumulate(words.begin(), words.end(), 0,
                      [&allowed](int acc, const string& word) {
      return acc + ranges::all_of(word, [&allowed](char c) {
        return allowed.find(c) != string::npos;
      });
    });
  }
};
