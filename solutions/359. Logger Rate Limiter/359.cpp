class Logger {
 public:
  bool shouldPrintMessage(int timestamp, string message) {
    // Remove the messages that are 10 seconds from the current timestamp.
    while (!messageQueue.empty()) {
      const auto [headTimestamp, headMessage] = messageQueue.front();
      if (timestamp < headTimestamp + 10)
        break;
      messageQueue.pop_front();
      messageSet.erase(headMessage);
    }

    if (messageSet.count(message))
      return false;

    messageQueue.emplace_back(timestamp, message);
    messageSet.insert(message);
    return true;
  }

 private:
  // [(timestamp, message)]
  deque<pair<int, string>> messageQueue;
  unordered_set<string> messageSet;
};
