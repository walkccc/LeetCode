class Solution {
 public:
  int minimumLevels(vector<int>& possible) {
    const int n = possible.size();
    const vector<int> nums = getNums(possible);
    vector<int> prefix(n + 1);

    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    for (int i = 1; i < n; ++i)
      if (prefix[i] > prefix[n] - prefix[i])
        return i;

    return -1;
  }

 private:
  vector<int> getNums(const vector<int>& possible) {
    vector<int> nums;
    for (const int num : possible)
      nums.push_back(num == 1 ? 1 : -1);
    return nums;
  }
};
