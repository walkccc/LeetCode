class Solution {
 public:
  int minimumCost(string sentence, int k) {
    if (sentence.length() <= k)
      return 0;

    vector<string> words = getWords(sentence);

    // dp[i] := min cost of first i words
    vector<int> dp(words.size() + 1);

    for (int i = 1; i <= words.size(); ++i) {
      int n = words[i - 1].length();  // length of current row
      dp[i] = dp[i - 1] + (k - n) * (k - n);
      // gradually add words[j - 1], words[j - 2], ...
      for (int j = i - 1; j > 0; --j) {
        n += words[j - 1].length() + 1;
        if (n > k)
          break;
        dp[i] = min(dp[i], dp[j - 1] + (k - n) * (k - n));
      }
    }

    int lastRowLen = words.back().length();
    int i = words.size() - 2;

    while (i > 0 && lastRowLen + words[i].length() + 1 <= k)
      lastRowLen += words[i--].length() + 1;

    return *min_element(begin(dp) + i + 1, end(dp));
  }

 private:
  vector<string> getWords(const string& sentence) {
    vector<string> words;
    istringstream iss(sentence);
    for (string token; iss >> token;)
      words.push_back(token);
    return words;
  }
};
