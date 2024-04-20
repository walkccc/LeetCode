class Solution {
 public:
  int maxPalindromesAfterOperations(vector<string>& words) {
    int ans = 0;
    int pairs = getPairs(words);

    for (const int length : getSortedLengths(words)) {
      const int needPairs = length / 2;
      if (pairs < needPairs)
        return ans;
      ++ans;
      pairs -= needPairs;
    }

    return ans;
  }

 private:
  int getPairs(const vector<string>& words) {
    int pairs = 0;
    unordered_map<char, int> count;

    for (const string& word : words)
      for (const char c : word)
        ++count[c];

    for (const auto& [_, freq] : count)
      pairs += freq / 2;

    return pairs;
  }

  vector<int> getSortedLengths(const vector<string>& words) {
    vector<int> lengths;
    for (const string& word : words)
      lengths.push_back(word.length());
    ranges::sort(lengths);
    return lengths;
  }
};
