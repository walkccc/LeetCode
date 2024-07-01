class TodoList {
  public int addTask(int userId, String taskDescription, int dueDate, List<String> tags) {
    userIdToTaskIdToTasks.putIfAbsent(userId, new HashMap<>());
    userIdToTaskIdToTasks.get(userId).put(++taskId, new Task(taskDescription, dueDate, tags));
    taskIds.add(taskId);
    return taskId;
  }

  public List<String> getAllTasks(int userId) {
    List<String> res = new ArrayList<>();
    for (Task task : getTasksSortedByDueDate(userId))
      res.add(task.taskDescription);
    return res;
  }

  public List<String> getTasksForTag(int userId, String tag) {
    List<String> res = new ArrayList<>();
    for (Task task : getTasksSortedByDueDate(userId))
      if (task.tags.contains(tag))
        res.add(task.taskDescription);
    return res;
  }

  public void completeTask(int userId, int taskId) {
    if (!taskIds.contains(taskId))
      return;
    if (!userIdToTaskIdToTasks.containsKey(userId))
      return;
    Map<Integer, Task> taskIdToTasks = userIdToTaskIdToTasks.get(userId);
    if (!taskIdToTasks.containsKey(taskId))
      return;
    taskIdToTasks.remove(taskId);
  }

  private record Task(String taskDescription, int dueDate, List<String> tags) {}
  private int taskId = 0;
  private Set<Integer> taskIds = new HashSet<>();
  // {userId: {taskId: tasks}}
  private Map<Integer, Map<Integer, Task>> userIdToTaskIdToTasks = new HashMap<>();

  private List<Task> getTasksSortedByDueDate(int userId) {
    if (!userIdToTaskIdToTasks.containsKey(userId))
      return new ArrayList<>();
    TreeSet<Task> tasks = new TreeSet<>((a, b) -> a.dueDate - b.dueDate);
    for (Task task : userIdToTaskIdToTasks.get(userId).values())
      tasks.add(task);
    return new ArrayList<>(tasks);
  }
}
