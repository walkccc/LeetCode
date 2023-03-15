class Solution {
 public:
  int minCapability(vector<int>& nums, int k) {
    int l = *min_element(begin(nums), end(nums));
    int r = *max_element(begin(nums), end(nums));

    while (l < r) {
      const int m = (l + r) / 2;
      if (stolenHouses(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int stolenHouses(const vector<int>& nums, int capacity) {
    int stolen = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] <= capacity) {
        ++stolen;
        ++i;
      }
    return stolen;
  }
};
