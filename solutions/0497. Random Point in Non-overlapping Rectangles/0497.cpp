class Solution {
 public:
  Solution(vector<vector<int>>& rects) : rects(move(rects)) {
    for (const auto& r : this->rects)
      areas.push_back(getArea(r));
    partial_sum(begin(areas), end(areas), begin(areas));
  }

  vector<int> pick() {
    const int target = rand() % areas.back();
    const int index =
        upper_bound(begin(areas), end(areas), target) - begin(areas);
    const auto& r = rects[index];
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
