class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int ans = 0;
    unordered_map<int, int> lengthAt;

    for (const int a : arr) {
      if (const auto it = lengthAt.find(a - difference); it != lengthAt.cend())
        lengthAt[a] = it->second + 1;
      else
        lengthAt[a] = 1;
      ans = max(ans, lengthAt[a]);
    }

    return ans;
  }
};
