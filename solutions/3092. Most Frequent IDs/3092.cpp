class Solution {
 public:
  vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    vector<long long> ans;
    unordered_map<int, long> numCount;  // {num: freq}
    map<long, int> freqCount;           // {num's freq: freq}

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      const int f = freq[i];
      if (const auto it = numCount.find(num); it != numCount.cend()) {
        const int numFreq = it->second;
        if (--freqCount[numFreq] == 0)
          freqCount.erase(numFreq);
      }
      const long newFreq = numCount[num] + f;
      if (newFreq == 0) {
        numCount.erase(num);
      } else {
        numCount[num] = newFreq;
        ++freqCount[newFreq];
      }
      ans.push_back(freqCount.empty() ? 0 : freqCount.rbegin()->first);
    }

    return ans;
  }
};
