class Solution {
 public:
  int minimumSeconds(vector<int>& nums) {
    const int n = nums.size();
    int ans = n;
    unordered_map<int, vector<int>> numToIndices;

    for (int i = 0; i < n; ++i)
      numToIndices[nums[i]].push_back(i);

    for (const auto& [_, indices] : numToIndices) {
      int seconds = getSeconds(indices.front() + n, indices.back());
      for (int i = 1; i < indices.size(); ++i)
        seconds = max(seconds, getSeconds(indices[i], indices[i - 1]));
      ans = min(ans, seconds);
    }

    return ans;
  }

 private:
  // Returns the number of seconds required to make nums[i..j] the same.
  int getSeconds(int i, int j) {
    return (i - j) / 2;
  }
};
