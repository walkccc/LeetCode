class Solution {
  public int[] deckRevealedIncreasing(int[] deck) {
    final int n = deck.length;

    Arrays.sort(deck);

    Deque<Integer> dq = new ArrayDeque<>();
    dq.offerFirst(deck[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      dq.offerFirst(dq.getLast());
      dq.pollLast();
      dq.offerFirst(deck[i]);
    }

    for (int i = 0; i < n; ++i)
      deck[i] = dq.pollFirst();

    return deck;
  }
}
