WITH
  EmployeeTimes AS (
    SELECT DISTINCT employee_id, start_time AS `time`
    FROM Tasks
    UNION DISTINCT
    SELECT DISTINCT employee_id, end_time AS `time`
    FROM Tasks
  ),
  Segments AS (
    SELECT
      employee_id,
      `time` AS start_time,
      LEAD(`time`) OVER(PARTITION BY employee_id ORDER BY `time`) AS end_time
    FROM EmployeeTimes
  ),
  SegmentsCount AS (
    SELECT
      Segments.*,
      COUNT(*) AS concurrent_count
    FROM Segments
    INNER JOIN Tasks
      USING (employee_id)
    WHERE
      Segments.start_time >= Tasks.start_time
      AND Segments.end_time <= Tasks.end_time
    GROUP BY 1, 2, 3
  )
SELECT
  employee_id,
  FLOOR(
    SUM(
      TIME_TO_SEC(TIMEDIFF(end_time, start_time)) / 3600
    )
  ) AS total_task_hours,
  MAX(concurrent_count) AS max_concurrent_tasks
FROM SegmentsCount
GROUP BY 1
ORDER BY 1;
