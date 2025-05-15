SELECT
  Trips.request_at AS Day,
  ROUND(SUM(Trips.status != 'completed') / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
INNER JOIN Users AS Clients
  ON (Trips.client_id = Clients.users_id)
INNER JOIN Users AS Drivers
  ON (Trips.driver_id = Drivers.users_id)
WHERE Clients.banned = 'No'
  AND Drivers.banned = 'No'
  AND Trips.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY 1;
