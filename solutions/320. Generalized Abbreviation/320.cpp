class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> ans;
    dfs(word, 0, 0, {}, ans);
    return ans;
  }

 private:
  void dfs(const string& word, int i, int count, vector<string>&& path,
           vector<string>& ans) {
    if (i == word.length()) {
      ans.push_back(join(path) + getCountString(count));
      return;
    }

    // Abbreviate the word[i].
    dfs(word, i + 1, count + 1, std::move(path), ans);
    // Keep the word[i], so consume the count as a string
    path.push_back(getCountString(count) + word[i]);
    // Reset the count to 0.
    dfs(word, i + 1, 0, std::move(path), ans);
    path.pop_back();
  }

  string getCountString(int count) {
    return count > 0 ? to_string(count) : "";
  }

  string join(const vector<string>& path) {
    string joined;
    for (const string& s : path)
      joined += s;
    return joined;
  };
};
