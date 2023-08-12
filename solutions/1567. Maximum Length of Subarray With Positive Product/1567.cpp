class Solution {
 public:
  int getMaxLen(vector<int>& nums) {
    int ans = 0;
    int neg = 0;  // max length of the subarray ending with num so far
    int pos = 0;  // max length of the subarray ending with num so far

    for (const int num : nums) {
      pos = num == 0 ? 0 : pos + 1;
      neg = num == 0 || neg == 0 ? 0 : neg + 1;
      if (num < 0)
        swap(pos, neg);
      ans = max(ans, pos);
    }

    return ans;
  }
};
