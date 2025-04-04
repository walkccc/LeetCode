struct OfflineUser {
  int returnTimestamp;
  int userId;
  bool operator>(const OfflineUser& other) const {
    return returnTimestamp > other.returnTimestamp;
  }
};

class Solution {
 public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> ans(numberOfUsers);
    vector<int> online(numberOfUsers, true);
    // min-heap to track users that are offline
    priority_queue<OfflineUser, vector<OfflineUser>, greater<>> offlineQueue;
    int allMentionsCount = 0;

    ranges::sort(events, ranges::less{}, [](const vector<string>& event) {
      const int timestamp = stoi(event[1]);
      const char eventType = event[0][0];
      return pair<int, char>{timestamp, -eventType};
    });

    for (const vector<string>& event : events) {
      const string eventType = event[0];
      const int timestamp = stoi(event[1]);
      // Bring users back online if their offline period has ended.
      while (!offlineQueue.empty() &&
             offlineQueue.top().returnTimestamp <= timestamp)
        online[offlineQueue.top().userId] = true, offlineQueue.pop();
      if (eventType == "MESSAGE") {
        const string mentionsString = event[2];
        if (mentionsString == "ALL") {
          ++allMentionsCount;
        } else if (mentionsString == "HERE") {
          for (int userId = 0; userId < numberOfUsers; ++userId)
            if (online[userId])
              ++ans[userId];
        } else {
          for (const int userId : getUserIds(mentionsString))
            ++ans[userId];
        }
      } else if (eventType == "OFFLINE") {
        const int userId = stoi(event[2]);
        online[userId] = false;
        // Add to queue to bring back online after 60 units.
        offlineQueue.emplace(timestamp + 60, userId);
      }
    }

    // Add the "ALL" mentions to all users.
    for (int userId = 0; userId < numberOfUsers; ++userId)
      ans[userId] += allMentionsCount;
    return ans;
  }

 private:
  vector<int> getUserIds(const string& s) {
    vector<int> integers;
    istringstream iss(s);
    for (string id; iss >> id;)
      integers.push_back(stoi(id.substr(2)));
    return integers;
  }
};
