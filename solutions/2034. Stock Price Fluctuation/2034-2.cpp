class StockPrice {
 public:
  void update(int timestamp, int price) {
    if (const auto it = timestampToPrice.find(timestamp);
        it != timestampToPrice.cend()) {
      const int prevPrice = it->second;
      prices.erase(prices.equal_range(prevPrice).first);
    }
    timestampToPrice[timestamp] = price;
    prices.insert(price);
  }

  int current() {
    return timestampToPrice.rbegin()->second;
  }

  int maximum() {
    return *prices.rbegin();
  }

  int minimum() {
    return *prices.begin();
  }

 private:
  map<int, int> timestampToPrice;
  multiset<int> prices;
};
