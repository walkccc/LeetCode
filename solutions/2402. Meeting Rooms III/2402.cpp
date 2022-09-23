struct T {
  long endTime;
  int roomId;
};

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int> count(n);

    sort(begin(meetings), end(meetings));

    auto compare = [](const T& a, const T& b) {
      return a.endTime == b.endTime ? a.roomId > b.roomId
                                    : a.endTime > b.endTime;
    };
    priority_queue<T, vector<T>, decltype(compare)> occupied(compare);
    priority_queue<int, vector<int>, greater<>> availableRoomIds;

    for (int i = 0; i < n; ++i)
      availableRoomIds.push(i);

    for (const vector<int>& meeting : meetings) {
      const int start = meeting[0];
      const int end = meeting[1];
      // push meetings ending before this `meeting` in occupied to
      // `availableRoomsIds`
      while (!occupied.empty() && occupied.top().endTime <= start)
        availableRoomIds.push(occupied.top().roomId), occupied.pop();
      if (availableRoomIds.empty()) {
        const auto [newStart, roomId] = occupied.top();
        occupied.pop();
        ++count[roomId];
        occupied.push({newStart + (end - start), roomId});
      } else {
        const int roomId = availableRoomIds.top();
        availableRoomIds.pop();
        ++count[roomId];
        occupied.push({end, roomId});
      }
    }

    return max_element(begin(count), end(count)) - begin(count);
  }
};
