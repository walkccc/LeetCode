class StockPrice {
  public void update(int timestamp, int price) {
    if (timestampToPrice.containsKey(timestamp)) {
      final int prevPrice = timestampToPrice.get(timestamp);
      pricesCount.merge(prevPrice, -1, Integer::sum);
      if (pricesCount.get(prevPrice) == 0)
        pricesCount.remove(prevPrice);
    }
    timestampToPrice.put(timestamp, price);
    pricesCount.merge(price, 1, Integer::sum);
  }

  public int current() {
    return timestampToPrice.lastEntry().getValue();
  }

  public int maximum() {
    return pricesCount.lastKey();
  }

  public int minimum() {
    return pricesCount.firstKey();
  }

  private TreeMap<Integer, Integer> timestampToPrice = new TreeMap<>();
  private TreeMap<Integer, Integer> pricesCount = new TreeMap<>();
}
