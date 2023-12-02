class Bitset {
  public Bitset(int size) {
    for (int i = 0; i < size; ++i) {
      sb.append('0');
      rb.append('1');
    }
  }

  public void fix(int idx) {
    if (sb.charAt(idx) == '0')
      ++cnt;
    sb.setCharAt(idx, '1');
    rb.setCharAt(idx, '0');
  }

  public void unfix(int idx) {
    if (sb.charAt(idx) == '1')
      --cnt;
    sb.setCharAt(idx, '0');
    rb.setCharAt(idx, '1');
  }

  public void flip() {
    StringBuilder temp = sb;
    sb = rb;
    rb = temp;
    cnt = sb.length() - cnt;
  }

  public boolean all() {
    return cnt == sb.length();
  }

  public boolean one() {
    return cnt > 0;
  }

  public int count() {
    return cnt;
  }

  public String toString() {
    return sb.toString();
  }

  private StringBuilder sb = new StringBuilder(); // the original
  private StringBuilder rb = new StringBuilder(); // the reversed
  private int cnt = 0;
}
