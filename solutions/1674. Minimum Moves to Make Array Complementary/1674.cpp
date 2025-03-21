class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    const int n = nums.size();
    int ans = n;
    // delta[i] := the number of moves needed when target goes from i - 1 to i
    vector<int> delta(limit * 2 + 2);

    for (int i = 0; i < n / 2; ++i) {
      const int a = nums[i];
      const int b = nums[n - 1 - i];
      --delta[min(a, b) + 1];
      --delta[a + b];
      ++delta[a + b + 1];
      ++delta[max(a, b) + limit + 1];
    }

    // Initially, we need `moves` when the target is 2.
    for (int i = 2, moves = n; i <= limit * 2; ++i) {
      moves += delta[i];
      ans = min(ans, moves);
    }

    return ans;
  }
};
