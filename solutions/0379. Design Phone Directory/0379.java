class PhoneDirectory {
  /**
   * Initialize your data structure here
   *
   * @param maxNumbers - The maximum numbers that can be stored in the phone
   *                   directory.
   */
  public PhoneDirectory(int maxNumbers) {
    next = new int[maxNumbers];
    for (int i = 0; i < maxNumbers - 1; ++i)
      next[i] = i + 1;
    next[maxNumbers - 1] = 0;
  }

  /**
   * Provide a number which is not assigned to anyone.
   *
   * @return - Return an available number. Return -1 if none is available.
   */
  public int get() {
    if (next[number] == -1)
      return -1;

    final int availableNum = number;
    number = next[number];
    next[availableNum] = -1; // mark as used
    return ans;
  }

  /** Check if a number is available or not. */
  public boolean check(int number) {
    return next[number] != -1;
  }

  /** Recycle or release a number. */
  public void release(int number) {
    if (next[number] != -1)
      return;

    next[number] = this.number;
    this.number = number;
  }

  private int number; // current possible available number
  private int[] next; // next available number
}
