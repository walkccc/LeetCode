class Solution {
 public:
  int maxEqualFreq(vector<int>& nums) {
    int ans = 0;
    int maxFreq = 0;
    unordered_map<int, int> count;
    unordered_map<int, int> freq;

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      --freq[count[num]];
      ++count[num];
      ++freq[count[num]];
      maxFreq = max(maxFreq, count[num]);
      if (maxFreq == 1 || maxFreq * freq[maxFreq] == i ||
          (maxFreq - 1) * (freq[maxFreq - 1] + 1) == i)
        ans = i + 1;
    }

    return ans;
  }
};
