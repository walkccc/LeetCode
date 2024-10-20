class Cashier {
  public Cashier(int n, int discount, int[] products, int[] prices) {
    this.n = n;
    this.discount = discount;
    for (int i = 0; i < products.length; ++i)
      productToPrice.put(products[i], prices[i]);
  }

  public double getBill(int[] product, int[] amount) {
    ++count;
    int total = 0;
    for (int i = 0; i < product.length; ++i)
      total += productToPrice.get(product[i]) * amount[i];
    return count % n == 0 ? total * (1 - discount / 100.0) : total;
  }

  private int n;
  private int discount;
  private Map<Integer, Integer> productToPrice = new HashMap<>();
  private int count = 0;
}
