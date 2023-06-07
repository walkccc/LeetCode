class Solution {
 public:
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    // diffs[i] := reward1[i] - reward2[i].
    vector<int> diffs;

    for (int i = 0; i < reward1.size(); ++i)
      diffs.push_back(reward1[i] - reward2[i]);

    nth_element(begin(diffs), begin(diffs) + k, end(diffs), greater<>());
    return accumulate(begin(reward2), end(reward2), 0) +
           accumulate(begin(diffs), begin(diffs) + k, 0);
  }
};
