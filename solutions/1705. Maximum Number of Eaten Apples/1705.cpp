class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    const int n = apples.size();
    int ans = 0;
    using P = pair<int, int>;  // (the rotten day, the number of apples)
    priority_queue<P, vector<P>, greater<>> minHeap;

    for (int i = 0; i < n || !minHeap.empty(); ++i) {  // i := day
      // Remove the rotten apples.
      while (!minHeap.empty() && minHeap.top().first <= i)
        minHeap.pop();
      // Add today's apples.
      if (i < n && apples[i] > 0)
        minHeap.emplace(i + days[i], apples[i]);
      // Eat one apple today.
      if (!minHeap.empty()) {
        const auto [rottenDay, numApples] = minHeap.top();
        minHeap.pop();
        if (numApples > 1)
          minHeap.emplace(rottenDay, numApples - 1);
        ++ans;
      }
    }

    return ans;
  }
};
