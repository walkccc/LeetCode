class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    // To distribute marbles into k bags, there will be k - 1 cuts. If there's a
    // cut after weights[i], then weights[i] and weights[i + 1] will be added to
    // the cost. Also, no matter how we cut, weights[0] and weights[n - 1] will
    // be counted. So, the goal is to find the max/min k - 1 weights[i] +
    // weights[i + 1].
    vector<int> A;  // weights[i] + weights[i + 1]
    long long min = 0;
    long long max = 0;

    for (int i = 0; i + 1 < weights.size(); ++i)
      A.push_back(weights[i] + weights[i + 1]);

    ranges::sort(A);

    for (int i = 0; i < k - 1; ++i) {
      min += A[i];
      max += A[A.size() - 1 - i];
    }

    return max - min;
  }
};
