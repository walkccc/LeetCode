class AuthenticationManager {
 public:
  AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {}

  void generate(string tokenId, int currentTime) {
    tokenIdToExpiryTime[tokenId] = currentTime;
    times.emplace(currentTime);
  }

  void renew(string tokenId, int currentTime) {
    const auto it = tokenIdToExpiryTime.find(tokenId);
    if (it == tokenIdToExpiryTime.cend() ||
        currentTime >= it->second + timeToLive)
      return;
    times.erase(tokenIdToExpiryTime[tokenId]);
    tokenIdToExpiryTime[tokenId] = currentTime;
    times.emplace(currentTime);
  }

  int countUnexpiredTokens(int currentTime) {
    const auto it = times.lower_bound(currentTime - timeToLive + 1);
    times.erase(times.begin(), it);
    return times.size();
  }

 private:
  const int timeToLive;
  unordered_map<string, int> tokenIdToExpiryTime;
  set<int> times;
};
