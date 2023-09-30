class Solution {
 public:
  int numOfPairs(vector<string>& nums, string target) {
    const int n = target.length();
    int ans = 0;
    unordered_map<string, int> count;

    for (const string& num : nums) {
      const int k = num.length();
      if (k >= n)
        continue;
      if (target.substr(0, k) == num)
        ans += count[target.substr(k)];
      if (target.substr(n - k) == num)
        ans += count[target.substr(0, n - k)];
      ++count[num];
    }

    return ans;
  }
};
