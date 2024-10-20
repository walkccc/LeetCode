class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    unordered_map<string, int> map;  // {reversed word: its index}

    for (int i = 0; i < words.size(); ++i) {
      string word = words[i];
      ranges::reverse(word);
      map[word] = i;
    }

    for (int i = 0; i < words.size(); ++i) {
      const string& word = words[i];
      // a special case to prevent duplicate calculation
      if (const auto it = map.find("");
          it != map.cend() && it->second != i && isPalindrome(word))
        ans.push_back({i, it->second});
      for (int j = 1; j <= word.length(); ++j) {
        const string& l = word.substr(0, j);
        const string& r = word.substr(j);
        if (const auto it = map.find(l);
            it != map.cend() && it->second != i && isPalindrome(r))
          ans.push_back({i, it->second});
        if (const auto it = map.find(r);
            it != map.cend() && it->second != i && isPalindrome(l))
          ans.push_back({it->second, i});
      }
    }

    return ans;
  }

 private:
  bool isPalindrome(const string& word) {
    int l = 0;
    int r = word.length() - 1;
    while (l < r)
      if (word[l++] != word[r--])
        return false;
    return true;
  }
};
