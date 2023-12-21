class Solution {
 public:
  // Same as 2865. Beautiful Towers I
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    const int n = maxHeights.size();
    vector<long> maxSum(n);  // maxSum[i] := the maximum sum with peak i

    stack<int> stack{{-1}};
    long summ = 0;

    for (int i = 0; i < n; ++i) {
      summ = process(stack, maxHeights, i, summ);
      maxSum[i] = summ;
    }

    stack = std::stack<int>{{n}};
    summ = 0;

    for (int i = n - 1; i >= 0; --i) {
      summ = process(stack, maxHeights, i, summ);
      maxSum[i] += summ - maxHeights[i];
    }

    return ranges::max(maxSum);
  }

 private:
  long process(stack<int>& stack, vector<int>& maxHeights, int i, long summ) {
    while (stack.size() > 1 && maxHeights[stack.top()] > maxHeights[i]) {
      int j = stack.top();
      stack.pop();
      // The last abs(j - stack.top()) heights are maxHeights[j].
      summ -= abs(j - stack.top()) * static_cast<long>(maxHeights[j]);
    }
    // Put abs(i - stack.top()) * maxHeights[i] in the `heights`.
    summ += abs(i - stack.top()) * static_cast<long>(maxHeights[i]);
    stack.push(i);
    return summ;
  }
};
