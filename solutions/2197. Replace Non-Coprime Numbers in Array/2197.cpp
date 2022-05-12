class Solution {
 public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans;

    for (int num : nums) {
      while (!ans.empty() && gcd(ans.back(), num) > 1)
        num = lcm(ans.back(), num), ans.pop_back();
      ans.push_back(num);
    }

    return ans;
  }
};
