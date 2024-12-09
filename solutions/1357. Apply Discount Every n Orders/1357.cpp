class Cashier {
 public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
      : n(n), discount(discount) {
    for (int i = 0; i < products.size(); ++i)
      productToPrice[products[i]] = prices[i];
  }

  double getBill(vector<int> product, vector<int> amount) {
    ++count;
    int total = 0;
    for (int i = 0; i < product.size(); ++i)
      total += productToPrice[product[i]] * amount[i];
    return count % n == 0 ? total * (1 - discount / 100.0) : total;
  }

 private:
  const int n;
  const int discount;
  unordered_map<int, int> productToPrice;
  int count = 0;
};
