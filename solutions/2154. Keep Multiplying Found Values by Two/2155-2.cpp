class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    vector<bool> seen(1001);

    for (const int num : nums)
      seen[num] = true;

    while (original < 1001 && seen[original])
      original *= 2;

    return original;
  }
};
