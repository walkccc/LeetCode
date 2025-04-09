SELECT
  extra AS report_reason,
  COUNT(DISTINCT post_id) AS report_count
FROM Actions
WHERE
  ACTION = 'report'
  AND DATEDIFF('2019-07-05', action_date) = 1
GROUP BY 1;
