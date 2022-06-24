class Solution {
 public:
  int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    const int maxRight = max(startPos, fruits.back()[0]);
    int ans = 0;
    vector<int> amounts(1 + maxRight);
    vector<int> prefix(2 + maxRight);

    for (const auto& f : fruits)
      amounts[f[0]] = f[1];

    partial_sum(begin(amounts), end(amounts), begin(prefix) + 1);

    auto getFruits = [&](int leftSteps, int rightSteps) {
      const int l = max(0, startPos - leftSteps);
      const int r = min(maxRight, startPos + rightSteps);
      return prefix[r + 1] - prefix[l];
    };

    // go right first
    const int maxRightSteps = min(maxRight - startPos, k);
    for (int rightSteps = 0; rightSteps <= maxRightSteps; ++rightSteps) {
      const int leftSteps = max(0, k - 2 * rightSteps);  // turn left
      ans = max(ans, getFruits(leftSteps, rightSteps));
    }

    // go left first
    const int maxLeftSteps = min(startPos, k);
    for (int leftSteps = 0; leftSteps <= maxLeftSteps; ++leftSteps) {
      const int rightSteps = max(0, k - 2 * leftSteps);  // turn right
      ans = max(ans, getFruits(leftSteps, rightSteps));
    }

    return ans;
  }
};
