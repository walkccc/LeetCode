SELECT
  Posts.post_id,
  IFNULL(
    GROUP_CONCAT(
      DISTINCT Keywords.topic_id
      ORDER BY Keywords.topic_id
    ),
    'Ambiguous!'
  ) AS topic
FROM Posts
LEFT JOIN Keywords
  ON (CONCAT(' ', LOWER(Posts.content), ' ') LIKE CONCAT('% ', LOWER(Keywords.word), ' %'))
GROUP BY 1;
