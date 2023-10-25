class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    ranges::sort(position);

    int l = 1;
    int r = position.back() - position.front();

    while (l < r) {
      const int mid = r - (r - l) / 2;
      if (numBalls(position, mid) >= m)  // Too many balls.
        l = mid;
      else  // Too few balls.
        r = mid - 1;
    }

    return l;
  }

 private:
  int numBalls(const vector<int>& position, int force) {
    int balls = 0;
    int prevPosition = -force;
    for (const int pos : position)
      if (pos - prevPosition >= force) {
        ++balls;
        prevPosition = pos;
      }
    return balls;
  }
};
