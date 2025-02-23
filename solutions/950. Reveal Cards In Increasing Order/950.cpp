class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    ranges::sort(deck, greater<int>());

    deque<int> dq{deck[0]};

    for (int i = 1; i < deck.size(); ++i) {
      dq.push_front(dq.back());
      dq.pop_back();
      dq.push_front(deck[i]);
    }

    return {dq.begin(), dq.end()};
  }
};
