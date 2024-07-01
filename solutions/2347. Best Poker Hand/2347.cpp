class Solution {
 public:
  string bestHand(vector<int>& ranks, vector<char>& suits) {
    if (ranges::all_of(suits,
                       [&suits](const char suit) { return suit == suits[0]; }))
      return "Flush";

    constexpr int kMax = 13;
    vector<int> count(kMax + 1);

    for (const int rank : ranks)
      ++count[rank];

    const int max = ranges::max(count);
    if (max > 2)
      return "Three of a Kind";
    if (max == 2)
      return "Pair";
    return "High Card";
  }
};
