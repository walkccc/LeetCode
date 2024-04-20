WITH
  Request AS (
    SELECT COUNT(DISTINCT sender_id, send_to_id) AS `count`
    FROM FriendRequest
  ),
  Accepted AS (
    SELECT IFNULL(COUNT(DISTINCT requester_id, accepter_id), 0) AS `count`
    FROM RequestAccepted
  )
SELECT IF(
    `Request`.count = 0,
    0,
    ROUND(Accepted.`count` / Request.`count`, 2)
  ) AS accept_rate
FROM Request, Accepted;
