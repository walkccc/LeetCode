class Solution {
 public:
  int nextGreaterElement(int n) {
    string s = to_string(n);
    ranges::next_permutation(s);
    const long ans = stol(s);
    return ans > INT_MAX || ans <= n ? -1 : ans;
  }
};
