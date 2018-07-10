
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>日付入力のためのフォームを生成したい</title>
</head>
<body>
<?php
  # $_POSTの要素数を数え、フォームがPOSTされたかどうか判定します。
  if (count($_POST) > 0) {
    $year  = @$_POST['year'];
    $month = @$_POST['month'];
    $day   = @$_POST['day'];

    if (checkdate($month, $day, $year)) {
      echo '<p>' . h($year) . '年' . h($month) . '月' . h($day) .
          '日は正しい日付です。</p>';
    } else {
      echo '<p>' . h($year) . '年' . h($month) . '月' . h($day) .
          '日は正しい日付ではありません。</p>';
    }
  }

  function h($string) { // HTMLでのエスケープ処理をする関数
    return htmlspecialchars($string, ENT_QUOTES);
  }
?>
<form method="post" action="">
<?php
  echo '<select name="year">' . "\n";
  $start = date('Y') - 20;
  $end   = date('Y') + 20;
  for ($i = $start; $i <= $end; $i++) {
    echo '<option value="' . $i . '">' . $i . '</option>' . "\n";
  }
  echo '</select>年' . "\n";
  echo '<select name="month">' . "\n";
  for ($i = 1; $i <= 12; $i++) {
    echo '<option value="' . $i . '">' . $i . '</option>' . "\n";
  }
  echo '</select>月' . "\n";
  echo '<select name="day">' . "\n";
  for ($i = 1; $i <= 31; $i++) {
    echo '<option value="' . $i . '">' . $i . '</option>' . "\n";
  }
  echo '</select>' . "\n";
?>
<input type="submit" value="グラフを表示" />
</form>
</body>
</html>