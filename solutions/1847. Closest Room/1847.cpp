class Solution {
 public:
  vector<int> closestRoom(vector<vector<int>>& rooms,
                          vector<vector<int>>& queries) {
    vector<int> ans(queries.size());
    set<int> roomIds;

    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);

    auto descSize = [](const auto& a, const auto& b) { return a[1] > b[1]; };
    sort(begin(rooms), end(rooms), descSize);
    sort(begin(queries), end(queries), descSize);

    int i = 0;  // rooms' pointer
    for (const auto& q : queries) {
      while (i < rooms.size() && rooms[i][1] >= q[1])
        roomIds.insert(rooms[i++][0]);
      ans[q[2]] = searchClosestRoomId(roomIds, q[0]);
    }

    return ans;
  }

 private:
  int searchClosestRoomId(set<int>& roomIds, int preferred) {
    const auto it = roomIds.lower_bound(preferred);
    const int id1 = it == cbegin(roomIds) ? -1 : *(prev(it));
    const int id2 = it == cend(roomIds) ? -1 : *it;
    if (id1 == -1)
      return id2;
    if (id2 == -1)
      return id1;
    if (abs(preferred - id1) <= abs(preferred - id2))
      return id1;
    return id2;
  }
};
