class Solution {
 public:
  int minImpossibleOR(vector<int>& nums) {
    int ans = 1;
    const unordered_set<int> numsSet{begin(nums), end(nums)};

    while (numsSet.count(ans))
      ans <<= 1;

    return ans;
  }
};
