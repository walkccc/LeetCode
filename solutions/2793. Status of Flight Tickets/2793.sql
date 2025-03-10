SELECT
  Passengers.passenger_id,
  IF(
    RANK() OVER(
      PARTITION BY Passengers.flight_id
      ORDER BY Passengers.booking_time
    ) <= Flights.capacity,
    'Confirmed',
    'Waitlist'
  ) AS status
FROM Passengers
INNER JOIN Flights
  USING (flight_id)
ORDER BY 1;
