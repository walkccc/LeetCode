class Solution {
 public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans;

    for (int num : nums) {
      while (!ans.empty() && std::gcd(ans.back(), num) > 1)
        num = std::lcm(ans.back(), num), ans.pop_back();
      ans.push_back(num);
    }

    return ans;
  }
};
