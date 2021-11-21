class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    unordered_map<string, int> map;  // {reversed word: its index}

    for (int i = 0; i < words.size(); ++i) {
      string word = words[i];
      reverse(begin(word), end(word));
      map[word] = i;
    }

    for (int i = 0; i < words.size(); ++i) {
      const string& word = words[i];
      // special case to prevent duplicate calculation
      if (map.count("") && map[""] != i && isPalindrome(word))
        ans.push_back({i, map[""]});
      for (int j = 1; j <= word.length(); ++j) {
        const string& l = word.substr(0, j);
        const string& r = word.substr(j);
        if (map.count(l) && map[l] != i && isPalindrome(r))
          ans.push_back({i, map[l]});
        if (map.count(r) && map[r] != i && isPalindrome(l))
          ans.push_back({map[r], i});
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
