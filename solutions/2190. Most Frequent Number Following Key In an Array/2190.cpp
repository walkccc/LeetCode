class Solution {
 public:
  int mostFrequent(vector<int>& nums, int key) {
    vector<int> count(1001);

    for (int i = 0; i + 1 < nums.size(); ++i)
      if (nums[i] == key)
        ++count[nums[i + 1]];

    return ranges::max_element(count) - count.begin();
  }
};
