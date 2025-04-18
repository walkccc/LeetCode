class Solution {
 public:
  long long maximumSumOfHeights(vector<int>& heights) {
    const int n = heights.size();
    vector<long> maxSum(n);  // maxSum[i] := the maximum sum with peak i

    stack<int> stack{{-1}};
    long sum = 0;

    for (int i = 0; i < n; ++i) {
      sum = process(stack, heights, i, sum);
      maxSum[i] = sum;
    }

    stack = std::stack<int>{{n}};
    sum = 0;

    for (int i = n - 1; i >= 0; --i) {
      sum = process(stack, heights, i, sum);
      maxSum[i] += sum - heights[i];
    }

    return ranges::max(maxSum);
  }

 private:
  long process(stack<int>& stack, const vector<int>& heights, int i, long sum) {
    while (stack.size() > 1 && heights[stack.top()] > heights[i]) {
      const int j = stack.top();
      stack.pop();
      // The last abs(j - stack.top()) heights are `heights[j]`.
      sum -= static_cast<long>(abs(j - stack.top())) * heights[j];
    }
    // Put abs(i - stack.top()) * heights[i] in `heights`.
    sum += static_cast<long>(abs(i - stack.top())) * heights[i];
    stack.push(i);
    return sum;
  }
};
