class ProductOfNumbers {
  public ProductOfNumbers() {
    prefix = new ArrayList<>(List.of(1));
  }

  public void add(int num) {
    if (num == 0)
      prefix = new ArrayList<>(List.of(1));
    else
      prefix.add(prefix.get(prefix.size() - 1) * num);
  }

  public int getProduct(int k) {
    return k >= prefix.size() ? 0
                              : prefix.get(prefix.size() - 1) / prefix.get(prefix.size() - k - 1);
  }

  private List<Integer> prefix = new ArrayList<>();
}
