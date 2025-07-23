class Solution {
 public:
  bool equalFrequency(string word) {
    vector<int> count(26);

    for (const char c : word)
      ++count[c - 'a'];

    // Try to remove each letter, then check if the frequency of all the letters
    // in `word` are equal.
    for (const char c : word) {
      --count[c - 'a'];
      if (equalFreq(count))
        return true;
      ++count[c - 'a'];
    }

    return false;
  }

 private:
  static constexpr int kMax = 101;

  bool equalFreq(const vector<int>& count) {
    int minfreq = kMax;
    int maxfreq = 0;
    for (const int freq : count)
      if (freq > 0) {
        minfreq = min(minfreq, freq);
        maxfreq = max(maxfreq, freq);
      }
    return minfreq == maxfreq;
  }
};
