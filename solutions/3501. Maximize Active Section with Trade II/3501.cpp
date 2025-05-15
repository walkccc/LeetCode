#include <ranges>

struct Group {
  int start;
  int length;
};

class SparseTable {
 public:
  SparseTable(const vector<int>& nums)
      : n(nums.size()), st(std::bit_width(n) + 1, vector<int>(n + 1)) {
    copy(nums.begin(), nums.end(), st[0].begin());
    for (int i = 1; i <= bit_width(n); ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  }

  // Returns max(nums[l..r]).
  int query(unsigned l, unsigned r) const {
    const int i = bit_width(r - l + 1) - 1;
    return max(st[i][l], st[i][r - (1 << i) + 1]);
  }

 private:
  const unsigned n;
  vector<vector<int>> st;  // st[i][j] := max(nums[j..j + 2^i - 1])
};

class Solution {
 public:
  vector<int> maxActiveSectionsAfterTrade(string s,
                                          vector<vector<int>>& queries) {
    const int n = s.length();
    const int ones = ranges::count(s, '1');
    const auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);
    if (zeroGroups.empty())
      return vector<int>(queries.size(), ones);

    const SparseTable st(getZeroMergeLengths(zeroGroups));
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      const int left = zeroGroupIndex[l] == -1
                           ? -1
                           : (zeroGroups[zeroGroupIndex[l]].length -
                              (l - zeroGroups[zeroGroupIndex[l]].start));
      const int right = zeroGroupIndex[r] == -1
                            ? -1
                            : (r - zeroGroups[zeroGroupIndex[r]].start + 1);
      const auto [startAdjacentGroupIndex, endAdjacentGroupIndex] =
          mapToAdjacentGroupIndices(
              zeroGroupIndex[l] + 1,
              s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1);
      int activeSections = ones;
      if (s[l] == '0' && s[r] == '0' &&
          zeroGroupIndex[l] + 1 == zeroGroupIndex[r])
        activeSections = max(activeSections, ones + left + right);
      else if (startAdjacentGroupIndex <= endAdjacentGroupIndex)
        activeSections = max(
            activeSections,
            ones + st.query(startAdjacentGroupIndex, endAdjacentGroupIndex));
      if (s[l] == '0' &&
          zeroGroupIndex[l] + 1 <=
              (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1))
        activeSections =
            max(activeSections,
                ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);
      if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
        activeSections =
            max(activeSections,
                ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);
      ans.push_back(activeSections);
    }

    return ans;
  }

 private:
  // Returns the zero groups and the index of the zero group that contains the
  // i-th character.
  pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
    vector<Group> zeroGroups;
    vector<int> zeroGroupIndex;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        if (i > 0 && s[i - 1] == '0')
          ++zeroGroups.back().length;
        else
          zeroGroups.push_back({i, 1});
      }
      zeroGroupIndex.push_back(zeroGroups.size() - 1);
    }
    return {zeroGroups, zeroGroupIndex};
  }

  // Returns the sums of the lengths of the adjacent groups.
  vector<int> getZeroMergeLengths(const vector<Group>& zeroGroups) {
    vector<int> zeroMergeLengths;
    for (const auto& [a, b] : zeroGroups | views::pairwise)
      zeroMergeLengths.push_back(a.length + b.length);
    return zeroMergeLengths;
  }

  // Returns the indices of the adjacent groups that contain l and r completely.
  //
  // e.g.    groupIndices = [0, 1, 2, 3]
  // adjacentGroupIndices = [0 (0, 1), 1 (1, 2), 2 (2, 3)]
  // map(startGroupIndex = 1, endGroupIndex = 3) -> (1, 2)
  pair<int, int> mapToAdjacentGroupIndices(int startGroupIndex,
                                           int endGroupIndex) {
    return {startGroupIndex, endGroupIndex - 1};
  }
};
