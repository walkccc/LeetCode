WITH
  ServerNeighbors AS (
    SELECT
      status_time,
      session_status,
      LEAD(status_time) OVER(
        PARTITION BY server_id
        ORDER BY status_time
      ) AS next_status_time
    FROM Servers
  )
SELECT
  FLOOR(
    SUM(
      TIMESTAMPDIFF(SECOND, status_time, next_status_time)
    ) / 86400
  ) AS total_uptime_days
FROM ServerNeighbors
WHERE ServerNeighbors.session_status = 'start';
