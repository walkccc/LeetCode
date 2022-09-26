class Solution {
  public int[] deckRevealedIncreasing(int[] deck) {
    final int n = deck.length;

    Arrays.sort(deck);

    Deque<Integer> q = new ArrayDeque<>();
    q.addFirst(deck[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      q.addFirst(q.getLast());
      q.pollLast();
      q.addFirst(deck[i]);
    }

    for (int i = 0; i < n; ++i)
      deck[i] = q.pollFirst();

    return deck;
  }
}
