class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.contains(endWord))
      return 0;

    queue<string> q{{beginWord}};

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        string word = q.front();
        q.pop();
        for (int i = 0; i < word.length(); ++i) {
          const char cache = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[i] = c;
            if (word == endWord)
              return step + 1;
            if (wordSet.contains(word)) {
              q.push(word);
              wordSet.erase(word);
            }
          }
          word[i] = cache;
        }
      }

    return 0;
  }
};
