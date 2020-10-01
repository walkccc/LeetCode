class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    const int n = A.size();

    int ans = n + 1;
    deque<int> deque;
    vector<int> prefixSum(n + 1);

    for (int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + A[i];

    for (int i = 0; i < n + 1; ++i) {
      while (!deque.empty() && prefixSum[i] - prefixSum[deque.front()] >= K)
        ans = min(ans, i - deque.front()), deque.pop_front();
      while (!deque.empty() && prefixSum[i] <= prefixSum[deque.back()])
        deque.pop_back();
      deque.push_back(i);
    }

    return ans <= n ? ans : -1;
  }
};