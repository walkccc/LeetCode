class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    const int n = A.size();
    int ans = n + 1;
    deque<int> q;
    vector<long> prefix(n + 1);

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + A[i];

    for (int i = 0; i < n + 1; ++i) {
      while (!q.empty() && prefix[i] - prefix[q.front()] >= K)
        ans = min(ans, i - q.front()), q.pop_front();
      while (!q.empty() && prefix[i] <= prefix[q.back()])
        q.pop_back();
      q.push_back(i);
    }

    return ans <= n ? ans : -1;
  }
};
