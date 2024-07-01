class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    queue<vector<string>> paths{{{beginWord}}};  // {{"hit"}}

    while (!paths.empty()) {
      unordered_set<string> currentLevelVisited;
      for (int sz = paths.size(); sz > 0; --sz) {
        vector<string> path = paths.front();
        paths.pop();                    // {"hit"}
        string lastWord = path.back();  // "hit"
        for (int i = 0; i < lastWord.length(); ++i) {
          char cache = lastWord[i];  // Cache = 'i'
          for (char c = 'a'; c <= 'z'; ++c) {
            lastWord[i] = c;                // "hit" -> "hot" (temporarily)
            if (wordSet.count(lastWord)) {  // Find "hot" in the wordSet.
              currentLevelVisited.insert(lastWord);  // Mark "hot" as visited.
              vector<string> nextPath(path);
              nextPath.push_back(lastWord);  // nextPath = {"hit", "hot"}
              if (lastWord == endWord)
                ans.push_back(nextPath);
              else
                paths.push(nextPath);
            }
          }
          lastWord[i] = cache;  // Convert "hot" back to "hit".
        }
      }
      for (const string& word : currentLevelVisited)
        wordSet.erase(word);
    }

    return ans;
  }
};
