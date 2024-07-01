class CombinationIterator {
  public CombinationIterator(String characters, int combinationLength) {
    final int n = characters.length();
    final int k = combinationLength;

    // Generate bitmasks from 0..00 to 1..11
    for (int mask = 0; mask < 1 << n; mask++) {
      // Use bitmasks with k 1-bits
      if (Integer.bitCount(mask) == k) {
        // Convert bitmask into combination
        // 111 --> "abc", 000 --> ""
        // 110 --> "ab", 101 --> "ac", 011 --> "bc"
        StringBuilder curr = new StringBuilder();
        for (int j = 0; j < n; j++) {
          if ((mask & (1 << n - j - 1)) != 0) {
            curr.append(characters.charAt(j));
          }
        }
        combinations.push(curr.toString());
      }
    }
  }

  public String next() {
    return combinations.pop();
  }

  public boolean hasNext() {
    return (!combinations.isEmpty());
  }

  private Deque<String> combinations = new ArrayDeque<String>();
}
