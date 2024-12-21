class StockPrice {
 public:
  void update(int timestamp, int price) {
    if (timestampToPrice.contains(timestamp)) {
      const int prevPrice = timestampToPrice[timestamp];
      if (--pricesCount[prevPrice] == 0)
        pricesCount.erase(prevPrice);
    }
    timestampToPrice[timestamp] = price;
    ++pricesCount[price];
  }

  int current() {
    return timestampToPrice.rbegin()->second;
  }

  int maximum() {
    return pricesCount.rbegin()->first;
  }

  int minimum() {
    return pricesCount.begin()->first;
  }

 private:
  map<int, int> timestampToPrice;
  map<int, int> pricesCount;
};
