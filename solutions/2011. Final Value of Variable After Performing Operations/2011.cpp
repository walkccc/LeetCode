class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;

    for (const auto& op : operations)
      ans += op[1] == '+' ? 1 : -1;

    return ans;
  }
};
