class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    string prefix;
    for (const string& word : words) {
      prefix += word;
      if (prefix == s)
        return true;
    }
    return false;
  }
};
