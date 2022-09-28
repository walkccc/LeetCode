class Solution {
 public:
  int maxHappyGroups(int batchSize, vector<int>& groups) {
    int happy = 0;
    vector<int> freq(batchSize);

    for (int g : groups) {
      g %= batchSize;
      if (g == 0) {
        ++happy;
      } else if (freq[batchSize - g]) {
        --freq[batchSize - g];
        ++happy;
      } else {
        ++freq[g];
      }
    }

    return happy + dp(freq, 0, batchSize);
  }

 private:
  map<vector<int>, int> memo;

  // max # of partitions you can form given
  // current freq and current remainder r
  int dp(const vector<int>& freq, int r, const int& batchSize) {
    if (memo.count(freq))
      return memo[freq];

    int ans = 0;

    if (any_of(begin(freq), end(freq), [](int f) { return f != 0; })) {
      for (int i = 0; i < freq.size(); ++i)
        if (freq[i]) {
          vector<int> newFreq(freq);
          --newFreq[i];
          ans = max(ans, dp(newFreq, (r + i) % batchSize, batchSize));
        }
      if (r == 0)
        ++ans;
    }

    return memo[freq] = ans;
  }
};
