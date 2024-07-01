struct T {
  int pro;
  int cap;
  T(int pro, int cap) : pro(pro), cap(cap) {}
};

class Solution {
 public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits,
                           vector<int>& Capital) {
    auto compareC = [](const T& a, const T& b) { return a.cap > b.cap; };
    auto compareP = [](const T& a, const T& b) { return a.pro < b.pro; };
    priority_queue<T, vector<T>, decltype(compareC)> minHeap(compareC);
    priority_queue<T, vector<T>, decltype(compareP)> maxHeap(compareP);

    for (int i = 0; i < Capital.size(); ++i)
      minHeap.emplace(Profits[i], Capital[i]);

    while (k--) {
      while (!minHeap.empty() && minHeap.top().cap <= W)
        maxHeap.push(minHeap.top()), minHeap.pop();
      if (maxHeap.empty())
        break;
      W += maxHeap.top().pro, maxHeap.pop();
    }

    return W;
  }
};
