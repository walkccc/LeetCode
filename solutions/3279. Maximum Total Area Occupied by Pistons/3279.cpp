class Solution {
 public:
  long long maxArea(int height, vector<int>& positions, string directions) {
    long area = accumulate(positions.begin(), positions.end(), 0L);
    long ans = area;
    long diffPerSecond = 0;
    map<int, vector<int>> timeToIndices;

    for (int i = 0; i < positions.size(); ++i)
      if (directions[i] == 'U') {
        timeToIndices[height - positions[i]].push_back(i);
        timeToIndices[height - positions[i] + height].push_back(i);
        ++diffPerSecond;
      } else {
        timeToIndices[positions[i]].push_back(i);
        timeToIndices[positions[i] + height].push_back(i);
        --diffPerSecond;
      }

    int prevTime = 0;

    for (const auto& [time, indices] : timeToIndices) {
      area += (time - prevTime) * diffPerSecond;
      ans = max(ans, area);
      prevTime = time;
      for (const int i : indices)
        if (directions[i] == 'U') {
          directions[i] = 'D';
          diffPerSecond -= 2;
        } else {
          directions[i] = 'U';
          diffPerSecond += 2;
        }
    }

    return ans;
  }
};
