SELECT
  Age.age_bucket,
  ROUND(
    SUM(IF(Activities.activity_type = 'send', Activities.time_spent, 0)) /
    SUM(Activities.time_spent) * 100,
    2
  ) AS send_perc,
  ROUND(
    SUM(IF(Activities.activity_type = 'open', Activities.time_spent, 0)) /
    SUM(Activities.time_spent) * 100,
    2
  ) AS open_perc
FROM Activities
INNER JOIN Age
  USING (user_id)
GROUP BY 1;
