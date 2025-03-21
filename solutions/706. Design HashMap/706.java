class MyHashMap {
  public MyHashMap() {
    lists = new List[SIZE];
    for (int i = 0; i < SIZE; ++i)
      lists[i] = new ArrayList<>();
  }

  public void put(int key, int value) {
    for (int[] pair : lists[key % SIZE])
      if (pair[0] == key) {
        pair[1] = value;
        return;
      }
    lists[key % SIZE].add(new int[] {key, value});
  }

  public int get(int key) {
    for (int[] pair : lists[key % SIZE])
      if (pair[0] == key)
        return pair[1];
    return -1;
  }

  public void remove(int key) {
    for (int i = 0; i < lists[key % SIZE].size(); ++i)
      if (lists[key % SIZE].get(i)[0] == key) {
        lists[key % SIZE].remove(i);
        return;
      }
  }

  private static final int SIZE = 10000;
  List<int[]>[] lists; // Each slot stores the (key, value) list.
}
