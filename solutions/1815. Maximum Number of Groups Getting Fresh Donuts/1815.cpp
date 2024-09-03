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
  map<vector<int>, int> mem;

  // Returns the maximum number of partitions can be formed.
  int dp(const vector<int>& freq, int remainder, const int& batchSize) {
    if (const auto it = mem.find(freq); it != mem.cend())
      return it->second;

    int ans = 0;

    if (ranges::any_of(freq, [](int f) { return f != 0; })) {
      for (int i = 0; i < freq.size(); ++i)
        if (freq[i]) {
          vector<int> newFreq(freq);
          --newFreq[i];
          ans = max(ans, dp(newFreq, (remainder + i) % batchSize, batchSize));
        }
      if (remainder == 0)
        ++ans;
    }

    return mem[freq] = ans;
  }
};
