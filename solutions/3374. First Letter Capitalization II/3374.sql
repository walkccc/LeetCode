WITH RECURSIVE
  Words AS (
    -- Extract the first word and assign a token index.
    SELECT
      content_id,
      SUBSTRING_INDEX(content_text, ' ', 1) AS word,
      SUBSTRING(
        content_text,
        LENGTH(SUBSTRING_INDEX(content_text, ' ', 1)) + 2
      ) AS remaining_text,
      1 AS token_index
    FROM user_content
    UNION ALL
    -- Recursively extract the next word and increment the token index.
    SELECT
      content_id,
      SUBSTRING_INDEX(remaining_text, ' ', 1) AS word,
      SUBSTRING(
        remaining_text,
        LENGTH(SUBSTRING_INDEX(remaining_text, ' ', 1)) + 2
      ) AS remaining_text,
      token_index + 1 AS token_index
    FROM Words
    WHERE remaining_text != ''
  ),
  Converted AS (
    -- Combine the words back in original order with proper capitalization.
    SELECT
      content_id,
      GROUP_CONCAT(
        IF(
          word LIKE '%-%',
          CONCAT(
            UPPER(SUBSTRING(word, 1, 1)),
            LOWER(SUBSTRING(word, 2, LOCATE('-', word) - 2)),
            '-',
            UPPER(SUBSTRING(SUBSTRING_INDEX(word, '-', -1), 1, 1)),
            LOWER(SUBSTRING(SUBSTRING_INDEX(word, '-', -1), 2))
          ),
          CONCAT(
            UPPER(SUBSTRING(word, 1, 1)),
            LOWER(SUBSTRING(word, 2))
          )
        )
        ORDER BY token_index SEPARATOR ' '
      ) AS converted_text
    FROM Words
    GROUP BY 1
  )
SELECT
  UserContent.content_id,
  UserContent.content_text AS original_text,
  Converted.converted_text
FROM user_content AS UserContent
INNER JOIN Converted
  USING (content_id);
