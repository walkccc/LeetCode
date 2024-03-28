class Solution {
 public:
  vector<long long> findPrefixScore(vector<int>& nums) {
    vector<long long> ans;
    long long prefix = 0;
    int maxi = 0;

    for (const int num : nums) {
      maxi = max(maxi, num);
      prefix += num + maxi;
      ans.push_back(prefix);
    }

    return ans;
  }
};
