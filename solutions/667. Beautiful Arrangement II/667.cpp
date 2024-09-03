class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans;

    for (int i = 0; i < n - k; ++i)
      ans.push_back(i + 1);

    for (int i = 0; i < k; ++i)
      if (i % 2 == 0)
        ans.push_back(n - i / 2);
      else
        ans.push_back(n - k + (i + 1) / 2);

    return ans;
  }
};
