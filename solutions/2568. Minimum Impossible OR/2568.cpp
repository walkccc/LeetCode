class Solution {
 public:
  int minImpossibleOR(vector<int>& nums) {
    int ans = 1;
    const unordered_set<int> numsSet{nums.begin(), nums.end()};

    while (numsSet.contains(ans))
      ans <<= 1;

    return ans;
  }
};
