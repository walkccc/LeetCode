struct T {
  int pro;
  int cap;
};

class Solution {
 public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits,
                           vector<int>& Capital) {
    auto compareC = [](const T& a, const T& b) { return a.cap > b.cap; };
    auto compareP = [](const T& a, const T& b) { return a.pro < b.pro; };
    priority_queue<T, vector<T>, decltype(compareC)> pqCap(compareC);
    priority_queue<T, vector<T>, decltype(compareP)> pqPro(compareP);

    for (int i = 0; i < Capital.size(); ++i)
      pqCap.push({Profits[i], Capital[i]});

    while (k--) {
      while (!pqCap.empty() && pqCap.top().cap <= W)
        pqPro.push(pqCap.top()), pqCap.pop();
      if (pqPro.empty())
        break;
      W += pqPro.top().pro, pqPro.pop();
    }

    return W;
  }
};
