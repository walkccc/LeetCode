SELECT Playback.session_id
FROM Playback
LEFT JOIN Ads
  ON (
    Playback.customer_id = Ads.customer_id
    AND Ads.timestamp BETWEEN Playback.start_time AND Playback.end_time)
WHERE Ads.ad_id IS NULL;
