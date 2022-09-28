public class Solution {
  public String reorganizeString(String s) {
    Map<Character, Integer> count = new HashMap<>();
    int maxFreq = 0;

    for (final char c : s.toCharArray()) {
      count.merge(c, 1, Integer::sum);
      maxFreq = Math.max(maxFreq, count.get(c));
    }

    if (maxFreq > (s.length() + 1) / 2)
      return "";

    StringBuilder sb = new StringBuilder();
    // (freq, c)
    Queue<Pair<Integer, Character>> maxHeap =
        new PriorityQueue<>((a, b) -> b.getKey() - a.getKey());
    int prevFreq = 0;
    char prevChar = '@';

    for (final char c : count.keySet())
      maxHeap.offer(new Pair<>(count.get(c), c));

    while (!maxHeap.isEmpty()) {
      // get the most freq letter
      final int freq = maxHeap.peek().getKey();
      final char c = maxHeap.poll().getValue();
      sb.append(c);
      // add the previous letter back so that
      // any two adjacent characters are not the same
      if (prevFreq > 0)
        maxHeap.offer(new Pair<>(prevFreq, prevChar));
      prevFreq = freq - 1;
      prevChar = c;
    }

    return sb.toString();
  }
}
