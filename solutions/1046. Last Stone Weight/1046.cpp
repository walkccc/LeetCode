class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq{stones.begin(), stones.end()};

    while (pq.size() >= 2) {
      const int n1 = pq.top();
      pq.pop();
      const int n2 = pq.top();
      pq.pop();
      if (n1 != n2)
        pq.push(n1 - n2);
    }

    return pq.empty() ? 0 : pq.top();
  }
};
