<html>
  <head>
		<meta charset="utf-8"/>
	<link rel="stylesheet" href="css/graph.css">
	<link rel="stylesheet" href="css/style.css">
	<!--Load the AJAX API-->
	<!-- <script src="https://cdn.plot.ly/plotly-latest.min.js"></script>
	 -->
	 <script src="js/plotly-latest.min.js"></script>
	<link rel="stylesheet" href="./bootstrap/css/bootstrap.min.css">
	<script type="text/javascript" src="./js/jquery-3.3.1.min.js"></script>
  </head>

  <body>
	<form action="">
		<input type="button" value="グラフ読み込み"
			onClick="loadCSV('data/20180628.csv')" class="btn btn-primary"/>　
	</form>
	<!-- 日付選択フォーム -->
	<section class="chose_date_container">
		<h2>日付を選択：</h2>
		<form method="post" action="">
		<?php
			$today_year = date('Y');
			$today_month = date('n');
			$today_day = date('j');
			function set_date( $i, $today ){
				if( $i == $today ){
					echo '<option value="' . $i . '" selected="selected">' . $i . '</option>' . "\n";
				}else {
					echo '<option value="' . $i . '">' . $i . '</option>' . "\n";
				}
			}
			function set_date_with0( $i, $today ){
				if( $i == $today ){
					if( $i < 10 ){
						echo '<option value="0' . $i . '" selected="selected">0' . $i . '</option>' . "\n";
					}else {
						echo '<option value="' . $i . '" selected="selected">' . $i . '</option>' . "\n";
					}
				}else {
					if( $i < 10 ){
						echo '<option value="0' . $i . '">0' . $i . '</option>' . "\n";
					}else {
						echo '<option value="' . $i . '">' . $i . '</option>' . "\n";
					}
				}
			}
			echo '<select name="year" class="selected_year">' . "\n";
			$start = date('Y') - 5;
			$end   = date('Y') + 20;
			for ($i = $start; $i <= $end; $i++) {
				set_date($i, $today_year);
			}
			echo '</select>年' . "\n";
			echo '<select name="month" class="selected_month">' . "\n";
			for ($i = 1; $i <= 12; $i++) {
				set_date_with0($i, $today_month);
			}
			echo '</select>月' . "\n";
			echo '<select name="day" class="selected_day">' . "\n";
			for ($i = 1; $i <= 31; $i++) {
				set_date_with0($i, $today_day);
			}
			echo '</select>' . "\n";
		?>
		<!-- <input type="submit" value="グラフを表示" /> -->
		</form>
	</section>
	<h2>防犯カメラ装置の計測電流値</h2>
	<div id="chart_div"></div>

	<div class="test"></div>

	<!-- 
		load JS, php
	 -->
	<script src="js/readCSV.js"></script>
	<script src="./js/onchange.js"></script>
  </body>
</html>

