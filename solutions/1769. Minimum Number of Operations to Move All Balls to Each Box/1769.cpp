class Solution {
 public:
  vector<int> minOperations(string boxes) {
    vector<int> ans(boxes.length());

    for (int i = 0, count = 0, moves = 0; i < boxes.length(); ++i) {
      ans[i] += moves;
      count += boxes[i] - '0';
      moves += count;
    }

    for (int i = boxes.length() - 1, count = 0, moves = 0; i >= 0; --i) {
      ans[i] += moves;
      count += boxes[i] - '0';
      moves += count;
    }

    return ans;
  }
};
