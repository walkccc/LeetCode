SELECT COUNT(Subscriptions.account_id) AS accounts_count
FROM Subscriptions
LEFT JOIN Streams
  USING (account_id)
WHERE
  2021 BETWEEN YEAR(Subscriptions.start_date) AND YEAR(Subscriptions.end_date)
  AND YEAR(Streams.stream_date) != 2021;
