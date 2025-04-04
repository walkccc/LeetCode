class Solution {
  public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
    record Record(int count, int nextIndex) {}
    // records[i].count := the number of times that s2 starting from index i has
    // been fully matched with s1
    // records[i].nextIndex := the next index in s2 to be matched after
    // completing a full match starting from index i
    List<Record> records = new ArrayList<>();

    for (int i = 0; i < s2.length(); ++i) {
      int count = 0;
      int nextIndex = i;
      for (final char c : s1.toCharArray())
        if (s2.charAt(nextIndex) == c)
          if (++nextIndex == s2.length()) { // There's a match.
            ++count;
            nextIndex = 0;
          }
      records.add(new Record(count, nextIndex));
    }

    int matches = 0; // the number of matches between `s1` x n1 and `s2`
    int i = 0;       // the index in `s2` to start matching

    while (n1-- > 0) {
      matches += records.get(i).count;
      i = records.get(i).nextIndex;
    }

    return matches / n2;
  }
}
