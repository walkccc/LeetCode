class SnakeGame {
 public:
  /** Initialize your data structure here.
     @param width - screen width
     @param height - screen height
     @param food - A list of food positions
     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the
     second is at [1,0]. */
  SnakeGame(int width, int height, vector<vector<int>>& food)
      : width(width), height(height), food(food) {
    lookup.insert(getId(0, 0));
    body.push_back(getId(0, 0));
  }

  /** Moves the snake.
      @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
      @return The game's score after the move. Return -1 if game over.
      Game over when snake crosses the screen boundary or bites its body. */
  int std::move(string direction) {
    // the old head's position
    int i = body.front() / width;
    int j = body.front() % width;

    // Update the head's position and check if it's out-of-bounds.
    if (direction == "U" && --i < 0)
      return -1;
    if (direction == "L" && --j < 0)
      return -1;
    if (direction == "R" && ++j == width)
      return -1;
    if (direction == "D" && ++i == height)
      return -1;

    const int newHead = getId(i, j);

    // 1. Eat food and increase the size by 1.
    if (k < food.size() && i == food[k][0] && j == food[k][1]) {
      lookup.insert(newHead);
      body.push_front(newHead);
      ++k;
      return ++score;
    }

    // 2. new head != old tail and eat body!
    if (newHead != body.back() && lookup.contains(newHead))
      return -1;

    // 3. normal case
    // Remove the old tail first, then add new head because new head may be in
    // old tail's position.
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
