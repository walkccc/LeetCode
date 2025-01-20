class PhoneDirectory {
  public PhoneDirectory(int maxNumbers) {
    next = new int[maxNumbers];
    for (int i = 0; i < maxNumbers - 1; ++i)
      next[i] = i + 1;
    next[maxNumbers - 1] = 0;
  }

  public int get() {
    if (next[number] == -1)
      return -1;
    final int availableNum = number;
    number = next[number];
    next[availableNum] = -1; // Mark as used.
    return availableNum;
  }

  public boolean check(int number) {
    return next[number] != -1;
  }

  public void release(int number) {
    if (next[number] != -1)
      return;

    next[number] = this.number;
    this.number = number;
  }

  private int number; // the current possible available number
  private int[] next; // the next available numbers
}
