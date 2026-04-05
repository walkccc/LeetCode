class Solution {
 public:
  // Same as 2865. Beautiful Towers I
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    const int n = maxHeights.size();
    vector<long> maxSum(n);  // maxSum[i] := the maximum sum with peak i

    stack<int> stack{{-1}};
    long sum = 0;

    for (int i = 0; i < n; ++i) {
      sum = process(stack, maxHeights, i, sum);
      maxSum[i] = sum;
    }

    stack = std::stack<int>{{n}};
    sum = 0;

    for (int i = n - 1; i >= 0; --i) {
      sum = process(stack, maxHeights, i, sum);
      maxSum[i] += sum - maxHeights[i];
    }

    return ranges::max(maxSum);
  }

 private:
  long process(stack<int>& stack, const vector<int>& maxHeights, int i,
               long sum) {
    while (stack.size() > 1 && maxHeights[stack.top()] > maxHeights[i]) {
      const int j = stack.top();
      stack.pop();
      // The last abs(j - stack.top()) maxHeights are `maxHeights[j]`.
      sum -= static_cast<long>(abs(j - stack.top())) * maxHeights[j];
    }
    // Put abs(i - stack.top()) * maxHeights[i] in `maxHeights`.
    sum += static_cast<long>(abs(i - stack.top())) * maxHeights[i];
    stack.push(i);
    return sum;
  }
};
