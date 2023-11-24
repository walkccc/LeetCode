WITH
  LogToRowNumber AS (
    SELECT
      log_id,
      ROW_NUMBER() OVER(ORDER BY log_id) AS `row_number`
    FROM Logs
  )
SELECT
  MIN(log_id) AS start_id,
  MAX(log_id) AS end_id
FROM LogToRowNumber
GROUP BY log_id - `row_number`;
