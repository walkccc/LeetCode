class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int ans;
    int count = 0;

    for (const int num : nums) {
      if (count == 0)
        ans = num;
      count += num == ans ? 1 : -1;
    }

    return ans;
  }
};