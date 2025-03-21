class DiningPhilosophers {
  std::mutex mutex;

 public:
  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    mutex.lock();
    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
    mutex.unlock();
  }
};
