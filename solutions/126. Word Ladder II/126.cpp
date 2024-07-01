class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordSet{wordList.begin(), wordList.end()};
    if (!wordSet.count(endWord))
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
    unordered_set<string> currentLevelWords{beginWord};

    while (!currentLevelWords.empty()) {
      for (const string& word : currentLevelWords)
        wordSet.erase(word);
      unordered_set<string> nextLevelWords;
      bool reachEndWord = false;
      for (const string& parent : currentLevelWords) {
        vector<string> children;
        getChildren(parent, wordSet, children);
        for (const string& child : children) {
          if (wordSet.count(child)) {
            nextLevelWords.insert(child);
            graph[parent].push_back(child);
          }
          if (child == endWord)
            reachEndWord = true;
        }
      }
      if (reachEndWord)
        return true;
      currentLevelWords = move(nextLevelWords);
    }

    return false;
  }

  void getChildren(const string& parent, const unordered_set<string>& wordSet,
                   vector<string>& children) {
    string s(parent);

    for (int i = 0; i < s.length(); ++i) {
      const char cache = s[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c == cache)
          continue;
        s[i] = c;
        if (wordSet.count(s))
          children.push_back(s);
      }
      s[i] = cache;
    }
  }

  void dfs(const unordered_map<string, vector<string>>& graph,
           const string& word, const string& endWord, vector<string>&& path,
           vector<vector<string>>& ans) {
    if (word == endWord) {
      ans.push_back(path);
      return;
    }
    if (!graph.count(word))
      return;

    for (const string& child : graph.at(word)) {
      path.push_back(child);
      dfs(graph, child, endWord, move(path), ans);
      path.pop_back();
    }
  }
};
