class Solution {
 public:
  int numOfStrings(vector<string>& patterns, string word) {
    return ranges::count_if(patterns, [&word](const string& pattern) {
      return word.find(pattern) != word.npos;
    });
  }
};
