WITH
  RECURSIVE TaskToSubtask AS (
    SELECT task_id, subtasks_count AS subtask_id FROM Tasks
    UNION ALL
    SELECT task_id, subtask_id - 1 FROM TaskToSubtask
    WHERE subtask_id > 1
  )
SELECT * FROM TaskToSubtask
EXCEPT
SELECT * FROM Executed;
