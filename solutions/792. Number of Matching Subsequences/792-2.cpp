class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    int ans = 0;
    // [(i, j)] := words[i] and the letter words[i][j] is waiting for
    vector<vector<pair<int, int>>> bucket(26);

    // For each word, it's waiting for word[0].
    for (int i = 0; i < words.size(); ++i)
      bucket[words[i][0] - 'a'].emplace_back(i, 0);

    for (const char c : s) {
      // Let prevBucket = bucket[c] and clear bucket[c].
      vector<pair<int, int>> prevBucket;
      swap(prevBucket, bucket[c - 'a']);
      for (auto& [i, j] : prevBucket)
        // All the letters in words[i] are matched.
        if (++j == words[i].length())
          ++ans;
        else
          bucket[words[i][j] - 'a'].emplace_back(i, j);
    }

    return ans;
  }
};
