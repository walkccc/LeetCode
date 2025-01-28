class Solution {
 public:
  vector<int> countOfPairs(int n, int x, int y) {
    if (x > y)
      swap(x, y);

    const int ringLen = y - x + 1;
    const int leftLineLen = x - 1;
    const int rightLineLen = n - y;

    vector<int> ans(n);
    ans = addVectors(ans, bothInRing(n, ringLen));
    ans = addVectors(ans, bothInTheSameLine(n, leftLineLen));
    ans = addVectors(ans, bothInTheSameLine(n, rightLineLen));
    ans = addVectors(ans, lineToRing(n, leftLineLen, ringLen));
    ans = addVectors(ans, lineToRing(n, rightLineLen, ringLen));
    ans = addVectors(ans, lineToLine(n, x, y, leftLineLen, rightLineLen));
    for (int& freq : ans)
      freq *= 2;
    return ans;
  }

 private:
  // Returns the contribution from the scenario where two houses are located in
  // the ring.
  vector<int> bothInRing(int n, int ringLen) {
    vector<int> res(n);
    for (int k = 1; k <= (ringLen - 1) / 2; ++k)
      res[k - 1] += ringLen;
    if (ringLen % 2 == 0)
      res[ringLen / 2 - 1] += ringLen / 2;
    return res;
  }

  // Returns the contribution from the scenario where two houses are either
  // located in the left line [1, x) or the right line (y, n].
  vector<int> bothInTheSameLine(int n, int lineLen) {
    vector<int> res(n);
    for (int k = 1; k <= lineLen; ++k)
      res[k - 1] += lineLen - k;
    return res;
  }

  // Returns the contribution from the scenario where one house is either
  // located in the left line [1, x) or the right line (y, n] and the other
  // house is located in the cycle.
  vector<int> lineToRing(int n, int lineLen, int ringLen) {
    vector<int> res(n);
    for (int k = 1; k <= lineLen + ringLen; ++k) {
      // min(
      //   at most k - 1 since we need to give 1 to the line,
      //   at most ringLen / 2 since for length > ringLen / 2, it can always be
      //     calculated as ringLen - ringLen / 2
      // )
      const int maxInRingLen = min(k - 1, ringLen / 2);
      // max(at least 0, at lest k - lineLen)
      const int minInRingLen = max(0, k - lineLen);
      if (minInRingLen <= maxInRingLen) {
        // Each ring length contributes 2 to the count due to the split of
        // paths when entering the ring: One path traverses the upper half of
        // the ring, and the other traverses the lower half.
        // This is illustrated as follows:
        //   Path 1: ... -- x -- (upper half of the ring)
        //   Path 2: ... -- x -- (lower half of the ring)
        res[k - 1] += (maxInRingLen - minInRingLen + 1) * 2;
        if (minInRingLen == 0)
          // Subtract 1 since there's no split.
          res[k - 1] -= 1;
        if (maxInRingLen * 2 == ringLen)
          // Subtract 1 since the following case only contribute one:
          //   ... -- x -- (upper half of the ring) -- middle point
          //   ... -- x -- (upper half of the ring) -- middle point
          res[k - 1] -= 1;
      }
    }
    return res;
  }

  // Returns the contribution from the scenario where one house is in the left
  // line [1, x) and the other house is in the right line (y, n].
  vector<int> lineToLine(int n, int x, int y, int leftLineLen,
                         int rightLineLen) {
    vector<int> res(n);
    for (int k = 1; k <= leftLineLen + rightLineLen + 2; ++k) {
      // min(
      //   at most leftLineLen,
      //   at most k - 1 - (x < y) since we need to give 1 to the right line
      //     and if x < y we need to give another 1 to "x - y".
      // )
      const int maxInLeft = min(leftLineLen, k - 1 - (x < y));
      // max(at least 1, at least k - rightLineLen - (x < y))
      const int minInLeft = max(1, k - rightLineLen - (x < y));
      if (minInLeft <= maxInLeft)
        res[k - 1] += maxInLeft - minInLeft + 1;
    }
    return res;
  }

  vector<int> addVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a.size());
    transform(a.begin(), a.end(), b.begin(), res.begin(), plus<int>());
    return res;
  };
};
