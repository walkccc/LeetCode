class Solution {
 public:
  long long subsequenceSumOr(vector<int>& nums) {
    long ans = 0;
    long prefix = 0;

    for (const int num : nums) {
      prefix += num;
      ans |= num | prefix;
    }

    return ans;
  }
};
