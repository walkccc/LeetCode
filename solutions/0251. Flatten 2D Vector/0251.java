class Vector2D {
  public Vector2D(int[][] v) {
    for (int[] arr : v)
      for (final int a : arr)
        vec.add(a);
  }

  public int next() {
    return vec.get(i++);
  }

  public boolean hasNext() {
    return i < vec.size();
  }

  private List<Integer> vec = new ArrayList<>();
  private int i = 0;
}
