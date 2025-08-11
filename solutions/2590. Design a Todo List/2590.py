from dataclasses import dataclass


@dataclass(frozen=True)
class Task:
  taskDescription: str
  dueDate: int
  tags: list[str]


class TodoList:
  def __init__(self):
    self.taskId = 0
    self.taskIds = set()
    self.userIdToTaskIdToTasks: dict[int, dict[int, list[Task]]] = {}

  def addTask(self, userId: int, taskDescription: str, dueDate: int,
              tags: list[str]) -> int:
    self.taskId += 1
    taskIdToTasks = self.userIdToTaskIdToTasks.setdefault(userId, {})
    taskIdToTasks[self.taskId] = Task(taskDescription, dueDate, tags)
    self.taskIds.add(self.taskId)
    return self.taskId

  def getAllTasks(self, userId: int) -> list[str]:
    return [task.taskDescription
            for task in self._getTasksSortedByDueDate(userId)]

  def getTasksForTag(self, userId: int, tag: str) -> list[str]:
    return [task.taskDescription
            for task in self._getTasksSortedByDueDate(userId)
            if tag in task.tags]

  def completeTask(self, userId: int, taskId: int) -> None:
    if taskId not in self.taskIds:
      return
    if userId not in self.userIdToTaskIdToTasks:
      return
    taskIdToTasks = self.userIdToTaskIdToTasks[userId]
    if taskId not in taskIdToTasks:
      return
    del taskIdToTasks[taskId]

  def _getTasksSortedByDueDate(self, userId: int) -> list[Task]:
    if userId not in self.userIdToTaskIdToTasks:
      return []
    taskIdToTasks = self.userIdToTaskIdToTasks[userId]
    return sorted(
        [task for task in taskIdToTasks.values()],
        key=lambda x: x.dueDate)
