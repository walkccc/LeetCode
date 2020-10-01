/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf4);
 */

public class Solution extends Reader4 {
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return The number of actual characters read
   */
  public int read(char[] buf, int n) {
    char[] buf4 = new char[4]; // dynamic buffer
    int i = 0; // point to buf

    while (true) {
      final int n4 = read4(buf4); // will return [0..4]
      for (int i4 = 0; i4 < n4 && i < n; ++i4)
        buf[i++] = buf4[i4];
      if (n4 == 0 || i == n)
        return i;
    }
  }
}