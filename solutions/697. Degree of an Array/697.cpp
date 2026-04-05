class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    int ans = 0;
    int degree = 0;
    unordered_map<int, int> debut;
    unordered_map<int, int> count;

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i];
      if (!debut.contains(num))
        debut[num] = i;
      if (++count[num] > degree) {
        degree = count[num];
        ans = i - debut[num] + 1;
      } else if (count[num] == degree) {
        ans = min(ans, i - debut[num] + 1);
      }
    }

    return ans;
  }
};
