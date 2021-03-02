class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(begin(deck), end(deck), greater<int>());

    deque<int> deque{deck[0]};

    for (int i = 1; i < deck.size(); ++i) {
      deque.push_front(deque.back());
      deque.pop_back();
      deque.push_front(deck[i]);
    }

    return {begin(deque), end(deque)};
  }
};
