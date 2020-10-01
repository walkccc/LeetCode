class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(begin(wordList), end(wordList));
    if (!wordSet.count(endWord)) return 0;

    int ans = 0;
    queue<string> queue{{beginWord}};

    while (!queue.empty()) {
      ++ans;
      for (int i = queue.size(); i > 0; --i) {
        string word = queue.front(); queue.pop();
        for (int j = 0; j < word.length(); ++j) {
          const char cache = word[j];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[j] = c;
            if (word == endWord) return ans + 1;
            if (wordSet.count(word)) {
              wordSet.erase(word);
              queue.push(word);
            }
          }
          word[j] = cache;
        }
      }
    }

    return 0;
  }
};
