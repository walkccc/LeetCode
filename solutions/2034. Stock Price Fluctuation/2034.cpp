class StockPrice {
 public:
  void update(int timestamp, int price) {
    if (timestampToPrice.count(timestamp)) {
      const int prevPrice = timestampToPrice[timestamp];
      prices.erase(prices.equal_range(prevPrice).first);
    }
    timestampToPrice[timestamp] = price;
    prices.insert(price);
  }

  int current() {
    return rbegin(timestampToPrice)->second;
  }

  int maximum() {
    return *rbegin(prices);
  }

  int minimum() {
    return *begin(prices);
  }

 private:
  map<int, int> timestampToPrice;
  multiset<int> prices;
};
