class Solution {
  public String maximumBinaryString(String binary) {
    //     e.g. binary = "100110"
    // Do Operation 2 -> "100011"
    // Do Operation 1 -> "111011"
    // So, the index of the only '0' is prefixOnes + zeros - 1.
    final int zeros = (int) binary.chars().filter(c -> c == '0').count();
    final int prefixOnes = binary.indexOf('0');

    // Make the entire String as 1s.
    StringBuilder sb = new StringBuilder("1".repeat(binary.length()));

    // Make the only '0' if necessary.
    if (prefixOnes != -1)
      sb.setCharAt(prefixOnes + zeros - 1, '0');
    return sb.toString();
  }
}
