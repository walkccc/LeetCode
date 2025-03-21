class Solution {
 public:
  // Similar to 1995. Count Special Quadruplets
  int divisibleTripletCount(vector<int>& nums, int d) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int j = nums.size() - 1; j > 0; --j) {  // 'j' also represents k.
      for (int i = j - 1; i >= 0; --i)
        ans += count[(-(nums[i] + nums[j]) % d + d) % d];
      ++count[nums[j] % d];  // j := k
    }

    return ans;
  }
};
