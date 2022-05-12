class RandomizedSet {
  /**
   * Inserts a value to the set. Returns true if the set did not already contain the specified
   * element.
   */
  public boolean insert(int val) {
    if (valToIndex.containsKey(val))
      return false;

    valToIndex.put(val, vals.size());
    vals.add(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  public boolean remove(int val) {
    if (!valToIndex.containsKey(val))
      return false;

    final int index = valToIndex.get(val);
    // following two lines order are important when vals.size() == 1
    valToIndex.put(last(vals), index);
    valToIndex.remove(val);
    vals.set(index, last(vals));
    vals.remove(vals.size() - 1);
    return true;
  }

  /** Get a random element from the set. */
  public int getRandom() {
    final int index = rand.nextInt(vals.size());
    return vals.get(index);
  }

  private Map<Integer, Integer> valToIndex = new HashMap<>(); // {val: index in vals}
  private List<Integer> vals = new ArrayList<>();
  private Random rand = new Random();

  private int last(List<Integer> vals) {
    return vals.get(vals.size() - 1);
  }
}
