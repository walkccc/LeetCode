class Solution {
 public:
  int maximumLength(string s) {
    const int n = s.length();
    int ans = -1;
    int runningLen = 0;
    char prevLetter = '@';
    // counts[i][j] := the frequency of ('a' + i) repeating j times
    vector<vector<int>> counts(26, vector<int>(n + 1));

    for (const char c : s)
      if (c == prevLetter) {
        ++counts[c - 'a'][++runningLen];
      } else {
        runningLen = 1;
        ++counts[c - 'a'][runningLen];
        prevLetter = c;
      }

    for (const vector<int>& count : counts)
      ans = max(ans, getMaxFreq(count, n));

    return ans;
  }

 private:
  // Returns the maximum frequency that occurs more than three times.
  int getMaxFreq(const vector<int>& count, int maxFreq) {
    int times = 0;
    for (int freq = maxFreq; freq >= 1; --freq) {
      times += count[freq];
      if (times >= 3)
        return freq;
    }
    return -1;
  }
};
