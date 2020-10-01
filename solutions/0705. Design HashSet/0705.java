class MyHashSet {
  public void add(int key) {
    set[key] = true;
  }

  public void remove(int key) {
    set[key] = false;
  }

  public boolean contains(int key) {
    return set[key];
  }

  private boolean[] set = new boolean[1000001];
}