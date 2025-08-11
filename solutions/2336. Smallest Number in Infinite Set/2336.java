class SmallestInfiniteSet {
  public int popSmallest() {
    if (added.isEmpty())
      return curr++;
    final int mn = added.first();
    added.remove(mn);
    return mn;
  }

  public void addBack(int num) {
    if (num < curr)
      added.add(num);
  }

  private int curr = 1;
  private TreeSet<Integer> added = new TreeSet<>();
}
