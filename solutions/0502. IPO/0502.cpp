struct Item {
  int profit;
  int capital;
};

class Solution {
 public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits,
                           vector<int>& Capital) {
    auto compareC = [](const Item& a, const Item& b) {
      return a.capital > b.capital;
    };
    auto compareP = [](const Item& a, const Item& b) {
      return a.profit < b.profit;
    };
    priority_queue<Item, vector<Item>, decltype(compareC)> pqCap(compareC);
    priority_queue<Item, vector<Item>, decltype(compareP)> pqPro(compareP);

    for (int i = 0; i < Capital.size(); ++i)
      pqCap.push({Profits[i], Capital[i]});

    while (k--) {
      while (!pqCap.empty() && pqCap.top().capital <= W)
        pqPro.push(pqCap.top()), pqCap.pop();
      if (pqPro.empty()) break;
      W += pqPro.top().profit, pqPro.pop();
    }

    return W;
  }
};