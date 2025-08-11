class Solution {
 public:
  vector<long long> findPrefixScore(vector<int>& nums) {
    vector<long long> ans;
    long prefix = 0;
    int mx = 0;

    for (const int num : nums) {
      mx = max(mx, num);
      prefix += num + mx;
      ans.push_back(prefix);
    }

    return ans;
  }
};
