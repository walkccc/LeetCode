class SmallestInfiniteSet {
  public int popSmallest() {
    if (added.isEmpty())
      return curr++;
    final int min = added.first();
    added.remove(min);
    return min;
  }

  public void addBack(int num) {
    if (num < curr)
      added.add(num);
  }

  private int curr = 1;
  private TreeSet<Integer> added = new TreeSet<>();
}
