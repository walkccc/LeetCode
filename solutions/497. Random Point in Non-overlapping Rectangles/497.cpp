class Solution {
 public:
  Solution(vector<vector<int>>& rects) : rects(std::move(rects)) {
    for (const vector<int>& r : this->rects)
      areas.push_back(getArea(r));
    partial_sum(areas.begin(), areas.end(), areas.begin());
  }

  vector<int> pick() {
    const int target = rand() % areas.back();
    const int index = ranges::upper_bound(areas, target) - areas.begin();
    const vector<int>& r = rects[index];
    return {rand() % (r[2] - r[0] + 1) + r[0],
            rand() % (r[3] - r[1] + 1) + r[1]};
  }

 private:
  const vector<vector<int>> rects;
  vector<int> areas;

  int getArea(const vector<int>& r) {
    return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
  }
};
