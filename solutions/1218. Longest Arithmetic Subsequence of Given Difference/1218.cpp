class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int ans = 0;
    unordered_map<int, int> lengthAt;

    for (int a : arr) {
      if (lengthAt.count(a - difference))
        lengthAt[a] = lengthAt[a - difference] + 1;
      else
        lengthAt[a] = 1;
      ans = max(ans, lengthAt[a]);
    }

    return ans;
  }
};
