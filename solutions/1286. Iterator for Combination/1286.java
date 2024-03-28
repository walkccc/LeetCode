class CombinationIterator {
  public CombinationIterator(String characters, int combinationLength) {
    final int n = characters.length();
    final int k = combinationLength;

    // generate bitmasks from 0..00 to 1..11
    for (int bitmask = 0; bitmask < 1 << n; bitmask++) {
      // use bitmasks with k 1-bits
      if (Integer.bitCount(bitmask) == k) {
        // convert bitmask into combination
        // 111 --> "abc", 000 --> ""
        // 110 --> "ab", 101 --> "ac", 011 --> "bc"
        StringBuilder curr = new StringBuilder();
        for (int j = 0; j < n; j++) {
          if ((bitmask & (1 << n - j - 1)) != 0) {
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
