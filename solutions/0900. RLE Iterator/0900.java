class RLEIterator {
  public RLEIterator(int[] A) {
    this.A = A;
  }

  public int next(int n) {
    while (index < A.length && A[index] < n) {
      n -= A[index];
      index += 2;
    }

    if (index == A.length)
      return -1;

    A[index] -= n;
    return A[index + 1];
  }

  private int index = 0;
  private int[] A;
}
