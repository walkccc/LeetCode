WITH
  LogsNeighbors AS (
    SELECT
      *,
      LAG(num) OVER(ORDER BY id) AS prev_num,
      LEAD(num) OVER(ORDER BY id) AS next_num
    FROM LOGS
  )
SELECT DISTINCT num AS ConsecutiveNums
FROM LogsNeighbors
WHERE
  num = prev_num
  AND num = next_num;
