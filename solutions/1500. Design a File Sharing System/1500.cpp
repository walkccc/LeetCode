class FileSharing {
 public:
  FileSharing(int m) {}

  int join(vector<int> ownedChunks) {
    const int userId = getMinUserId();
    userToChunks[userId] = {ownedChunks.begin(), ownedChunks.end()};
    for (const int chunk : ownedChunks)
      chunkToUsers[chunk].insert(userId);
    return userId;
  }

  void leave(int userID) {
    for (const int chunk : userToChunks[userID]) {
      chunkToUsers[chunk].erase(userID);
      if (chunkToUsers[chunk].empty())
        chunkToUsers.erase(chunk);
    }
    userToChunks.erase(userID);
    availableUserIds.push(userID);
  }

  vector<int> request(int userID, int chunkID) {
    const auto it = chunkToUsers.find(chunkID);
    if (it == chunkToUsers.end())
      return {};
    vector<int> userIds{it->second.begin(), it->second.end()};
    userToChunks[userID].insert(chunkID);
    chunkToUsers[chunkID].insert(userID);
    return userIds;
  }

 private:
  unordered_map<int, set<int>> userToChunks;
  unordered_map<int, set<int>> chunkToUsers;
  priority_queue<int, vector<int>, greater<>> availableUserIds;

  int getMinUserId() {
    if (availableUserIds.empty())
      return userToChunks.size() + 1;
    const int minUserId = availableUserIds.top();
    availableUserIds.pop();
    return minUserId;
  }
};
