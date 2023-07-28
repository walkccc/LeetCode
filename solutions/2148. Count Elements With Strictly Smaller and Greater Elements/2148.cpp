class Solution {
 public:
  int countElements(vector<int>& nums) {
    const int min = *min_element(nums.begin(), nums.end());
    const int max = *max_element(nums.begin(), nums.end());
    return count_if(nums.begin(), nums.end(),
                    [&](const int num) { return min < num && num < max; });
  }
};
