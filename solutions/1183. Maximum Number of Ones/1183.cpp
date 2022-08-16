class Solution {
 public:
  int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    int ans = 0;
    vector<vector<int>> submatrix(sideLength, vector<int>(sideLength));
    priority_queue<int> maxHeap;

    for (int i = 0; i < width; ++i)
      for (int j = 0; j < height; ++j)
        ++submatrix[i % sideLength][j % sideLength];

    for (const auto& row : submatrix)
      for (const int a : row)
        maxHeap.push(a);

    for (int i = 0; i < maxOnes; ++i)
      ans += maxHeap.top(), maxHeap.pop();

    return ans;
  }
};
