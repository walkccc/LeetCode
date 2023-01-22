class Robot {
  public Robot(int width, int height) {
    pos.add(new Pair<>(new int[] {0, 0}, "South"));
    for (int i = 1; i < width; ++i)
      pos.add(new Pair<>(new int[] {i, 0}, "East"));
    for (int j = 1; j < height; ++j)
      pos.add(new Pair<>(new int[] {width - 1, j}, "North"));
    for (int i = width - 2; i >= 0; --i)
      pos.add(new Pair<>(new int[] {i, height - 1}, "West"));
    for (int j = height - 2; j > 0; --j)
      pos.add(new Pair<>(new int[] {0, j}, "South"));
  }

  public void step(int num) {
    isOrigin = false;
    i = (i + num) % pos.size();
  }

  public int[] getPos() {
    return pos.get(i).getKey();
  }

  public String getDir() {
    return isOrigin ? "East" : pos.get(i).getValue();
  }

  private boolean isOrigin = true;
  private int i = 0;
  private List<Pair<int[], String>> pos = new ArrayList<>();
}
