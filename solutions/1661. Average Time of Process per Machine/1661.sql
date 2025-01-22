SELECT
  StartActivity.machine_id,
  ROUND(
    AVG(EndActivity.timestamp - StartActivity.timestamp),
    3
  ) AS processing_time
FROM Activity AS StartActivity
INNER JOIN Activity AS EndActivity
  USING (machine_id, process_id)
WHERE
  StartActivity.activity_type = 'start'
  AND EndActivity.activity_type = 'end'
GROUP BY 1;
