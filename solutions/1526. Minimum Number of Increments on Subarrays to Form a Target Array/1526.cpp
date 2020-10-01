class Solution {
 public:
  int minNumberOperations(vector<int>& target) {
    int ans = target.front();

    for (int i = 1; i < target.size(); ++i)
      if (target[i] > target[i - 1])
        ans += target[i] - target[i - 1];

    return ans;
  }
};