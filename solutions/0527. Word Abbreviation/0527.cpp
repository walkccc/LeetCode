class Solution {
 public:
  vector<string> wordsAbbreviation(vector<string>& words) {
    const int n = words.size();
    vector<string> ans;
    // prefix[i] := ans[i] takes words[i][0..prefix[i]]
    vector<int> prefix(n);

    for (const string& word : words)
      ans.push_back(getAbbrev(word, 0));

    for (int i = 0; i < n; ++i) {
      while (true) {
        vector<int> dupeIndices;
        for (int j = i + 1; j < n; ++j)
          if (ans[i] == ans[j])
            dupeIndices.push_back(j);
        if (dupeIndices.empty())
          break;
        dupeIndices.push_back(i);
        for (const int index : dupeIndices)
          ans[index] = getAbbrev(words[index], ++prefix[index]);
      }
    }

    return ans;
  }

 private:
  string getAbbrev(const string& s, int prefixIndex) {
    const int n = s.length();
    const int num = n - (prefixIndex + 1) - 1;
    const int numLength = num < 10 ? 1 : num < 100 ? 2 : 3;
    const int abbrevLength = (prefixIndex + 1) + numLength + 1;
    if (abbrevLength >= n)
      return s;
    return s.substr(0, prefixIndex + 1) + to_string(num) + s.back();
  }
};
