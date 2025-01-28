class Solution {
 public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences,
                         vector<int>& vFences) {
    constexpr int kMod = 1'000'000'007;

    hFences.push_back(1);
    hFences.push_back(m);
    vFences.push_back(1);
    vFences.push_back(n);

    ranges::sort(hFences);
    ranges::sort(vFences);

    const unordered_set<int> hGaps = getGaps(hFences);
    const unordered_set<int> vGaps = getGaps(vFences);
    int maxGap = -1;

    for (const int hGap : hGaps)
      if (vGaps.contains(hGap))
        maxGap = max(maxGap, hGap);

    return maxGap == -1 ? -1 : static_cast<long>(maxGap) * maxGap % kMod;
  }

 private:
  unordered_set<int> getGaps(const vector<int>& fences) {
    unordered_set<int> gaps;
    for (int i = 0; i < fences.size(); ++i)
      for (int j = 0; j < i; ++j)
        gaps.insert(fences[i] - fences[j]);
    return gaps;
  }
};
