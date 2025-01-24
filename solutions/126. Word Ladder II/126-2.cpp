class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordSet{wordList.begin(), wordList.end()};
    if (!wordSet.contains(endWord))
      return {};

    // {"hit": ["hot"], "hot": ["dot", "lot"], ...}
    unordered_map<string, vector<string>> graph;

    // Build the graph from the beginWord to the endWord.
    if (!bfs(beginWord, endWord, wordSet, graph))
      return {};

    vector<vector<string>> ans;
    dfs(graph, beginWord, endWord, {beginWord}, ans);
    return ans;
  }

 private:
  bool bfs(const string& beginWord, const string& endWord,
           unordered_set<string>& wordSet,
           unordered_map<string, vector<string>>& graph) {
    unordered_set<string> forwardWords{beginWord};
    unordered_set<string> backwardWords{endWord};
    bool backward = false;

    while (!forwardWords.empty() && !backwardWords.empty()) {
      for (const string& word : forwardWords)
        wordSet.erase(word);
      for (const string& word : backwardWords)
        wordSet.erase(word);
      // Always expand the smaller queue.
      if (forwardWords.size() > backwardWords.size()) {
        swap(forwardWords, backwardWords);
        backward = !backward;
      }
      unordered_set<string> nextLevelWords;
      bool reachEndWord = false;
      for (const string& parent : forwardWords) {
        for (const string& child :
             getChildren(parent, wordSet, backwardWords)) {
          // Should check if `child` is in `backwardWords` since we erase them
          // at the beginning of each while loop.
          if (wordSet.contains(child) || backwardWords.contains(child)) {
            nextLevelWords.insert(child);
            if (backward)
              graph[child].push_back(parent);
            else
              graph[parent].push_back(child);
          }
          // We've reached the end word since there's a word in the
          // `forwardWords` connecting to a word in `backwardWords`. Note that
          // we can't return here since we need to completely explore this
          // level.
          if (backwardWords.contains(child))
            reachEndWord = true;
        }
      }
      if (reachEndWord)
        return true;
      forwardWords = std::move(nextLevelWords);
    }

    return true;
  }

  vector<string> getChildren(const string& parent,
                             const unordered_set<string>& wordSet,
                             const unordered_set<string>& backwardWords) {
    vector<string> children;
    string s(parent);

    for (int i = 0; i < s.length(); ++i) {
      const char cache = s[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c == cache)
          continue;
        s[i] = c;  // Now is `child`
        if (wordSet.contains(s) || backwardWords.contains(s))
          children.push_back(s);
      }
      s[i] = cache;
    }

    return children;
  }

  void dfs(const unordered_map<string, vector<string>>& graph,
           const string& word, const string& endWord, vector<string>&& path,
           vector<vector<string>>& ans) {
    if (word == endWord) {
      ans.push_back(path);
      return;
    }
    if (!graph.contains(word))
      return;

    for (const string& child : graph.at(word)) {
      path.push_back(child);
      dfs(graph, child, endWord, std::move(path), ans);
      path.pop_back();
    }
  }
};
