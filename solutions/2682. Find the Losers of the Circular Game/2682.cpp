class Solution {
 public:
  vector<int> circularGameLosers(int n, int k) {
    vector<int> ans;
    vector<bool> seen(n);

    for (int friendIndex = 0, turn = 1; !seen[friendIndex];) {
      seen[friendIndex] = true;
      friendIndex += turn++ * k;
      friendIndex %= n;
    }

    for (int friendIndex = 0; friendIndex < n; ++friendIndex)
      if (!seen[friendIndex])
        ans.push_back(friendIndex + 1);

    return ans;
  }
};
