/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char* buf, int n) {
    int i = 0;  // buf's index

    // Put the remaining characteres in the buf4 to the buf.
    while (i4 < n4 && i < n)
      buf[i++] = buf4[i4++];

    // While we're not reaching the tail (< 4 characters).
    while (i + 4 < n) {
      const int k = read4(buf + i);  // Directly write to the buf.
      if (k == 0)                    // Reach the EOF.
        return i;
      i += k;
    }

    // Reach the tail.
    while (i < n) {
      if (i4 == n4) {      // All the characters in the buf4 are consumed.
        i4 = 0;            // Reset the buf4's index.
        n4 = read4(buf4);  // Read <= 4 characters from the file to the buf4.
        if (n4 == 0)       // Reach the EOF.
          return i;
      }
      buf[i++] = buf4[i4++];
    }

    return i;
  }

 private:
  char* buf4 = new char[4];
  int i4 = 0;  // buf4's index
  int n4 = 0;  // buf4's size
};
