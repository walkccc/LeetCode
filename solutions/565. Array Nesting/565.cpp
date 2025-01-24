class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;

    for (const int num : nums) {
      if (num == -1)
        continue;
      int index = num;
      int count = 0;
      while (nums[index] != -1) {
        const int cache = index;
        index = nums[index];
        nums[cache] = -1;
        ++count;
      }
      ans = max(ans, count);
    }

    return ans;
  }
};
