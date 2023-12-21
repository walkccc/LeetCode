class Solution {
 public:
  int countCompleteSubstrings(string word, int k) {
    const int uniqueLetters =
        unordered_set<char>{word.begin(), word.end()}.size();
    int ans = 0;

    for (int windowSize = k;
         windowSize <= k * uniqueLetters && windowSize <= word.length();
         windowSize += k)
      ans += countCompleteStrings(word, k, windowSize);

    return ans;
  }

 private:
  // Returns the number of complete substrings of `windowSize ` of the `word`.
  int countCompleteStrings(const string& word, int k, int windowSize) {
    int res = 0;
    int countLetters = 0;  // the number of letters in the running substring
    vector<int> count(26);

    for (int i = 0; i < word.length(); ++i) {
      ++count[word[i] - 'a'];
      ++countLetters;
      if (i > 0 && abs(word[i] - word[i - 1]) > 2) {
        count = vector<int>(26);
        // Start a new substring starting at word[i].
        ++count[word[i] - 'a'];
        countLetters = 1;
      }
      if (countLetters == windowSize + 1) {
        --count[word[i - windowSize] - 'a'];
        --countLetters;
      }
      if (countLetters == windowSize)
        res += ranges::all_of(count,
                              [k](int freq) { return freq == 0 || freq == k; })
                   ? 1
                   : 0;
    }

    return res;
  }
};
