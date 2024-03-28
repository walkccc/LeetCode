class Solution {
  public int[] deckRevealedIncreasing(int[] deck) {
    final int n = deck.length;

    Arrays.sort(deck);

    Deque<Integer> dq = new ArrayDeque<>();
    dq.addFirst(deck[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      dq.addFirst(dq.getLast());
      dq.pollLast();
      dq.addFirst(deck[i]);
    }

    for (int i = 0; i < n; ++i)
      deck[i] = dq.pollFirst();

    return deck;
  }
}
