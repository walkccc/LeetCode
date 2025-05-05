class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> concatenated;
    unordered_map<int, vector<int>> startToPiece;

    for (const vector<int>& piece : pieces)
      startToPiece[piece[0]] = piece;

    for (const int a : arr)
      if (startToPiece.contains(a))
        for (const int num : startToPiece[a])
          concatenated.push_back(num);

    return concatenated == arr;
  }
};
