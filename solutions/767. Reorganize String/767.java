class Solution {
  public String reorganizeString(String s) {
    Map<Character, Integer> count = new HashMap<>();
    int maxFreq = 0;

    for (final char c : s.toCharArray())
      maxFreq = Math.max(maxFreq, count.merge(c, 1, Integer::sum));

    if (maxFreq > (s.length() + 1) / 2)
      return "";

    StringBuilder sb = new StringBuilder();
    // (freq, c)
    Queue<Pair<Integer, Character>> maxHeap =
        new PriorityQueue<>((a, b) -> b.getKey().compareTo(a.getKey()));
    int prevFreq = 0;
    char prevChar = '@';

    for (final char c : count.keySet())
      maxHeap.offer(new Pair<>(count.get(c), c));

    while (!maxHeap.isEmpty()) {
      // Get the letter with the maximum frequency.
      final int freq = maxHeap.peek().getKey();
      final char c = maxHeap.poll().getValue();
      sb.append(c);
      // Add the previous letter back s.t. any two adjacent characters are not
      // the same.
      if (prevFreq > 0)
        maxHeap.offer(new Pair<>(prevFreq, prevChar));
      prevFreq = freq - 1;
      prevChar = c;
    }

    return sb.toString();
  }
}
