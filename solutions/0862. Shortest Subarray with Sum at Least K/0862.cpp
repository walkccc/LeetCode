class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    const int n = A.size();

    int ans = n + 1;
    deque<int> deque;
    vector<int> prefix(n + 1);

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = A[i] + prefix[i];

    for (int i = 0; i < n + 1; ++i) {
      while (!deque.empty() && prefix[i] - prefix[deque.front()] >= K)
        ans = min(ans, i - deque.front()), deque.pop_front();
      while (!deque.empty() && prefix[i] <= prefix[deque.back()])
        deque.pop_back();
      deque.push_back(i);
    }

    return ans <= n ? ans : -1;
  }
};
