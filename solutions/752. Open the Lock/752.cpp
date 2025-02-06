class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> seen{deadends.begin(), deadends.end()};
    if (seen.contains("0000"))
      return -1;
    if (target == "0000")
      return 0;

    queue<string> q{{"0000"}};

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        string word = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          const char cache = word[i];
          // Increase the i-th digit by 1.
          word[i] = word[i] == '9' ? '0' : word[i] + 1;
          if (word == target)
            return step;
          if (!seen.contains(word)) {
            q.push(word);
            seen.insert(word);
          }
          word[i] = cache;
          // Decrease the i-th digit by 1.
          word[i] = word[i] == '0' ? '9' : word[i] - 1;
          if (word == target)
            return step;
          if (!seen.contains(word)) {
            q.push(word);
            seen.insert(word);
          }
          word[i] = cache;
        }
      }

    return -1;
  }
};
