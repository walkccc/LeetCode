class Solution {
 public:
  int minCapability(vector<int>& nums, int k) {
    int l = ranges::min(nums);
    int r = ranges::max(nums);

    while (l < r) {
      const int m = (l + r) / 2;
      if (numStolenHouses(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numStolenHouses(const vector<int>& nums, int capacity) {
    int stolenHouses = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] <= capacity) {
        ++stolenHouses;
        ++i;
      }
    return stolenHouses;
  }
};
