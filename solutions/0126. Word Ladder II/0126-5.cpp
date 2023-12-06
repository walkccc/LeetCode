class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordSet{wordList.begin(), wordList.end()};
    if (!wordSet.count(endWord))
      return {};

    unordered_map<string, int> distFromBeginWord{{beginWord, 0}};
    if (!bfs(beginWord, endWord, wordSet, distFromBeginWord))
      return {};

    vector<vector<string>> ans;
    wordSet.insert(beginWord);
    dfs(endWord, beginWord, distFromBeginWord, wordSet, {endWord}, ans);
    return ans;
  }

 private:
  // Uses BFS to update the minimum steps to reach the `endWord` from the
  // `beginWord` by using the words in the `wordSet`.
  bool bfs(const string& beginWord, const string& endWord,
           unordered_set<string>& wordSet,
           unordered_map<string, int>& distFromBeginWord) {
    queue<string> q{{beginWord}};
    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        const string parent = q.front();
        q.pop();
        if (parent == endWord)
          return true;
        for (const string& child : getChildren(parent, wordSet)) {
          if (distFromBeginWord.count(child))
            continue;
          distFromBeginWord[child] = distFromBeginWord[parent] + 1;
          q.push(child);
        }
      }
    }
    return false;
  }

  void dfs(const string& word, const string& beginWord,
           const unordered_map<string, int>& distFromBeginWord,
           const unordered_set<string>& wordSet, vector<string>&& path,
           vector<vector<string>>& ans) {
    if (word == beginWord) {
      ans.push_back({path.rbegin(), path.rend()});
      return;
    }

    const int currDist = distFromBeginWord.at(word);

    for (const string& child : getChildren(word, wordSet)) {
      if (const auto it = distFromBeginWord.find(child);
          it != distFromBeginWord.cend() && it->second == currDist - 1) {
        path.push_back(child);
        dfs(child, beginWord, distFromBeginWord, wordSet, move(path), ans);
        path.pop_back();
      }
    }
  }

  vector<string> getChildren(const string& parent,
                             const unordered_set<string>& wordSet) {
    vector<string> children;
    string child(parent);
    for (int i = 0; i < child.length(); ++i) {
      const char cache = child[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c == cache)
          continue;
        child[i] = c;
        if (wordSet.count(child))
          children.push_back(child);
      }
      child[i] = cache;
    }
    return children;
  }
};
