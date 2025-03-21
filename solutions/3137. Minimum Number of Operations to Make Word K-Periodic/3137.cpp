class Solution {
 public:
  int minimumOperationsToMakeKPeriodic(string word, int k) {
    unordered_map<string, int> count;
    int maxFreq = 0;

    for (int i = 0; i < word.length(); i += k)
      ++count[word.substr(i, k)];

    for (const auto& [_, freq] : count)
      maxFreq = max(maxFreq, freq);

    return word.length() / k - maxFreq;
  }
};
