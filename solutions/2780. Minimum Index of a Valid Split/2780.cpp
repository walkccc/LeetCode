class Solution {
 public:
  int minimumIndex(vector<int>& nums) {
    const int n = nums.size();
    unordered_map<int, int> count1;
    unordered_map<int, int> count2;

    for (const int num : nums)
      ++count2[num];

    for (int i = 0; i < n; ++i) {
      const int freq1 = ++count1[nums[i]];
      const int freq2 = --count2[nums[i]];
      if (freq1 * 2 > i + 1 && freq2 * 2 > n - 1 - i)
        return i;
    }

    return -1;
  }
};
