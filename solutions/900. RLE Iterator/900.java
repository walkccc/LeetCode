class RLEIterator {
  public RLEIterator(int[] encoding) {
    this.encoding = encoding;
  }

  public int next(int n) {
    while (index < encoding.length && encoding[index] < n) {
      n -= encoding[index];
      index += 2;
    }

    if (index == encoding.length)
      return -1;

    encoding[index] -= n;
    return encoding[index + 1];
  }

  private int index = 0;
  private int[] encoding;
}
