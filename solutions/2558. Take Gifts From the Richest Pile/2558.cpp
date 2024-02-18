class Solution {
 public:
  long long pickGifts(vector<int>& gifts, int k) {
    long long ans = 0;
    priority_queue<int> maxHeap;

    for (const int gift : gifts)
      maxHeap.push(gift);

    for (int i = 0; i < k; ++i) {
      const int squaredMax = sqrt(maxHeap.top());
      maxHeap.pop();
      maxHeap.push(squaredMax);
    }

    while (!maxHeap.empty())
      ans += maxHeap.top(), maxHeap.pop();

    return ans;
  }
};
