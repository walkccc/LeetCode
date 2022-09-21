enum class State { DRAW, MOUSE_WIN, CAT_WIN };

class Solution {
 public:
  int catMouseGame(vector<vector<int>>& graph) {
    const int n = graph.size();
    // result of (cat, mouse, move)
    // move := 0 (mouse) / 1 (cat)
    vector<vector<vector<State>>> states(
        n, vector<vector<State>>(n, vector<State>(2)));
    vector<vector<vector<int>>> outDegree(
        n, vector<vector<int>>(n, vector<int>(2)));
    queue<tuple<int, int, int, State>> q;  // (cat, mouse, move, state)

    for (int cat = 0; cat < n; ++cat)
      for (int mouse = 0; mouse < n; ++mouse) {
        outDegree[cat][mouse][0] = graph[mouse].size();
        outDegree[cat][mouse][1] =
            graph[cat].size() - count(begin(graph[cat]), end(graph[cat]), 0);
      }

    // start from states that winner can be determined
    for (int cat = 1; cat < n; ++cat)
      for (int move = 0; move < 2; ++move) {
        // mouse is in the hole -> State::MOUSE_WIN
        states[cat][0][move] = State::MOUSE_WIN;
        q.emplace(cat, 0, move, State::MOUSE_WIN);
        // cat catches mouse -> State::CAT_WIN
        states[cat][cat][move] = State::CAT_WIN;
        q.emplace(cat, cat, move, State::CAT_WIN);
      }

    while (!q.empty()) {
      const auto [cat, mouse, move, state] = q.front();
      q.pop();
      if (cat == 2 && mouse == 1 && move == 0)
        return static_cast<int>(state);
      const int prevMove = move ^ 1;
      for (const int prev : graph[prevMove ? cat : mouse]) {
        const int prevCat = prevMove ? prev : cat;
        if (prevCat == 0)  // invalid
          continue;
        const int prevMouse = prevMove ? mouse : prev;
        // the state is already determined
        if (states[prevCat][prevMouse][prevMove] != State::DRAW)
          continue;
        if (prevMove == 0 && state == State::MOUSE_WIN ||
            prevMove == 1 && state == State::CAT_WIN ||
            --outDegree[prevCat][prevMouse][prevMove] == 0) {
          states[prevCat][prevMouse][prevMove] = state;
          q.emplace(prevCat, prevMouse, prevMove, state);
        }
      }
    }

    return static_cast<int>(states[2][1][0]);
  }
};
