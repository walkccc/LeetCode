class Solution {
 public:
  string addBoldTag(string s, vector<string>& dict) {
    string ans;
    vector<bool> bold(s.length());

    size_t end = 0;
    for (size_t i = 0; i < s.length(); ++i) {
      for (const string& word : dict)
        if (s.substr(i).rfind(word, 0) == 0)
          end = max(end, i + word.length());
      bold[i] = end > i;
    }

    for (int i = 0; i < s.length(); ++i) {
      if (!bold[i]) {
        ans += s[i];
        continue;
      }
      int j = i;
      while (j < s.length() && bold[j])
        ++j;
      ans += "<b>" + s.substr(i, j - i) + "</b>";
      i = j - 1;
    }

    return ans;
  }
};