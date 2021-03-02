class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    sort(begin(clips), end(clips));

    int i = 0;
    while (farthest < T) {
      while (i < clips.size() && clips[i][0] <= end)
        farthest = max(farthest, clips[i++][1]);
      if (end == farthest)
        return -1;
      ++ans;
      end = farthest;
    }

    return ans;
  }
};
