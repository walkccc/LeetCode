class MyHashMap {
  /** Initialize your data structure here. */
  public MyHashMap() {
    lists = new List[kSize];

    for (int i = 0; i < kSize; ++i)
      lists[i] = new ArrayList<>();
  }

  /** value will always be non-negative. */
  public void put(int key, int value) {
    for (int[] pair : lists[key % kSize])
      if (pair[0] == key) {
        pair[1] = value;
        return;
      }
    lists[key % kSize].add(new int[] {key, value});
  }

  /**
   * Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key
   */
  public int get(int key) {
    for (int[] pair : lists[key % kSize])
      if (pair[0] == key)
        return pair[1];
    return -1;
  }

  /**
   * Removes the mapping of the specified value key if this map contains a mapping
   * for the key
   */
  public void remove(int key) {
    for (int i = 0; i < lists[key % kSize].size(); ++i)
      if (lists[key % kSize].get(i)[0] == key) {
        lists[key % kSize].remove(i);
        return;
      }
  }

  private static final int kSize = 10000;
  List<int[]>[] lists; // each slot store (key, value) list
}
