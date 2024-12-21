class Logger {
 public:
  bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp < okTime[message])
      return false;

    okTime[message] = timestamp + 10;
    return true;
  }

 private:
  unordered_map<string, int> okTime;  // {message: ok time}
};
