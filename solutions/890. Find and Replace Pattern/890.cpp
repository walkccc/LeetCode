class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;

    for (const string& word : words)
      if (isIsomorphic(word, pattern))
        ans.push_back(word);

    return ans;
  }

 private:
  bool isIsomorphic(const string& w, const string& p) {
    vector<int> map_w(128);
    vector<int> map_p(128);

    for (int i = 0; i < w.length(); ++i) {
      if (map_w[w[i]] != map_p[p[i]])
        return false;
      map_w[w[i]] = i + 1;
      map_p[p[i]] = i + 1;
    }

    return true;
  }
};
