class Solution {
 public:
  int findSmallestInteger(vector<int>& nums, int value) {
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[(num % value + value) % value];

    for (int i = 0; i < nums.size(); ++i)
      if (--count[i % value] < 0)
        return i;

    return nums.size();
  }
};
