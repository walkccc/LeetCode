class Solution {
 public:
  int minMoves(vector<int>& nums, int k) {
    vector<int> ones;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 1)
        ones.push_back(i);

    // return median index of [i..i + k)
    auto getMedIndex = [&](int i) { return (i + (i + k - 1)) / 2; };

    // calculate the first group: window[0] = A[0..k)
    const int median = ones[getMedIndex(0)];
    int moves = 0;
    for (int i = 0; i < k; ++i)
      moves += abs(ones[i] - median);

    int ans = moves;

    for (int i = 1; i <= ones.size() - k; ++i) {
      const int oldMedianIndex = ones[getMedIndex(i - 1)];
      const int newMedianIndex = ones[getMedIndex(i)];
      if (k & 1)
        moves += newMedianIndex - oldMedianIndex;
      moves -= newMedianIndex - ones[i - 1];
      moves += ones[i + k - 1] - newMedianIndex;
      ans = min(ans, moves);
    }

    auto nThSum = [&](int n) { return n * (n + 1) / 2; };
    return ans - nThSum((k - 1) / 2) - nThSum(k / 2);
  }
};
