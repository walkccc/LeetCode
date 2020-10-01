class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordSet(begin(wordList), end(wordList));
    if (!wordSet.count(endWord)) return {};

    unordered_map<string, vector<string>> parentToChildren;
    unordered_set<string> currentLevelWords{beginWord};
    bool isFound = false;

    while (!currentLevelWords.empty()) {
      // remove words in current level
      for (const string& word : currentLevelWords)
        wordSet.erase(word);
      unordered_set<string> nextLevelWords;
      // `parent` will be used as a key in `parentToChildren`
      for (const string& parent : currentLevelWords) {
        string child = parent;
        // enumerate next level words
        for (int i = 0; i < child.length(); ++i) {
          const char cache = child[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            child[i] = c;
            if (wordSet.count(child)) {
              if (child == endWord)
                isFound = true;
              nextLevelWords.insert(child);
              parentToChildren[parent].push_back(child);
            }
          }
          child[i] = cache;
        }
      }
      if (isFound) break;
      currentLevelWords = move(nextLevelWords);
    }

    if (!isFound) return {};

    vector<vector<string>> ans;
    vector<string> path{beginWord};

    // construct the ans by `parentToChildren`
    function<void(const string&)> dfs = [&](const string& word) {
      if (word == endWord) {
        ans.push_back(path);
        return;
      }
      if (!parentToChildren.count(word)) return;

      for (const string& child : parentToChildren[word]) {
        path.push_back(child);
        dfs(child);
        path.pop_back();
      }
    };

    dfs(beginWord);

    return ans;
  }
};
