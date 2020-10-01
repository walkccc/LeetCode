class SnakeGame {
 public:
  SnakeGame(int width, int height, vector<vector<int>>& food)
      : width(width), height(height), food(food) {
    lookup.insert(getId(0, 0));
    body.push_back(getId(0, 0));
  }

  int move(string direction) {
    // old head's position
    int i = body.front() / width;
    int j = body.front() % width;

    // update head's position and check if out of bound
    if (direction == "U" && --i < 0)
      return -1;
    else if (direction == "L" && --j < 0)
      return -1;
    else if (direction == "R" && ++j == width)
      return -1;
    else if (direction == "D" && ++i == height)
      return -1;

    const int newHead = getId(i, j);

    // case 1: eat food and increase size by 1
    if (k < food.size() && i == food[k][0] && j == food[k][1]) {
      lookup.insert(newHead);
      body.push_front(newHead);
      ++k;
      return ++score;
    }

    // case 2: new head != old tail and eat body!
    if (newHead != body.back() && lookup.count(newHead)) return -1;

    // case 3: normal case
    // remove old tail first (important), then add new head
    // because new head may be in old tail's position
    lookup.erase(body.back());
    lookup.insert(newHead);
    body.pop_back();
    body.push_front(newHead);

    return score;
  }

 private:
  int width;
  int height;
  int score = 0;
  int k = 0;  // food's index
  vector<vector<int>> food;
  unordered_set<int> lookup;
  deque<int> body;  // snake's body

  int getId(int i, int j) {
    return i * width + j;
  }
};