class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (const int num : nums)
      if (!seen.insert(num).second)
        return true;

    return false;
  }
};
