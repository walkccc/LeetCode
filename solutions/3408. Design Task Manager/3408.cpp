struct Task {
  int userId;
  int taskId;
  int priority;

  Task() = default;
  Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}

  bool operator<(const Task& other) const {
    return priority == other.priority ? taskId > other.taskId
                                      : priority > other.priority;
  }
};

class TaskManager {
 public:
  unordered_map<int, Task> taskMap;  // {taskId: Task}
  set<Task> taskSet;  // Stores tasks sorted by priority and taskId.

  TaskManager(vector<vector<int>>& tasks) {
    for (const auto& task : tasks)
      add(task[0], task[1], task[2]);
  }

  void add(int userId, int taskId, int priority) {
    const Task task(userId, taskId, priority);
    taskMap[taskId] = task;
    taskSet.insert(task);
  }

  void edit(int taskId, int newPriority) {
    const Task task = taskMap[taskId];
    taskSet.erase(task);
    const Task editedTask = Task(task.userId, task.taskId, newPriority);
    taskSet.insert(editedTask);
    taskMap[taskId] = editedTask;
  }

  void rmv(int taskId) {
    const Task task = taskMap[taskId];
    taskSet.erase(task);
    taskMap.erase(taskId);
  }

  int execTop() {
    if (taskSet.empty())
      return -1;
    const Task task = *taskSet.begin();
    taskSet.erase(task);
    taskMap.erase(task.taskId);
    return task.userId;
  }
};
