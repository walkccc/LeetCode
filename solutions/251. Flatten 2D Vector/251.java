class Vector2D {
  public Vector2D(int[][] vec) {
    for (int[] arr : vec)
      for (final int a : arr)
        this.vec.add(a);
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
