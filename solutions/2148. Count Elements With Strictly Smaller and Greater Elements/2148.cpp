class Solution {
 public:
  int countElements(vector<int>& nums) {
    const int min = *min_element(begin(nums), end(nums));
    const int max = *max_element(begin(nums), end(nums));
    return count_if(begin(nums), end(nums),
                    [&](const int num) { return min < num && num < max; });
  }
};
