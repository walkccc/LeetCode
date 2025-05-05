class Solution {
 public:
  long long countBadPairs(vector<int>& nums) {
    long ans = 0;
    unordered_map<int, int> count;  // (nums[i] - i)

    for (int i = 0; i < nums.size(); ++i)
      //     count[nums[i] - i] := the number of good pairs
      // i - count[nums[i] - i] := the number of bad pairs
      ans += i - count[nums[i] - i]++;

    return ans;
  }
};
