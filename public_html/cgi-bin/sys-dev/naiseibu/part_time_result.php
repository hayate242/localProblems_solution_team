<?php
session_start();

define('DB_DATABASE','db27');
define('DB_USERNAME','db27');
define('DB_PASSWORD','db27pass');
define('PDO_DSN','mysql:dbhost=tbsed.info.yuge.ac.jp;dbname=' . DB_DATABASE);
//ユーザ名とパスワード
$username = $_SESSION["USERID"];
//本日の日付を取得
$today = date("Y-m-d");
$todays = explode("-",$today);

$flag=0;
$monthFlag = 0;


for($i = 0;$i<12;$i++){
  $sum[$i] = 0;
}

if($_SERVER['REQUEST_METHOD'] === 'POST'){
    $year = $_POST['year'];
    $month = $_POST['month'];

    $deleteDate = $_POST['deleteDate'];

    if($username){
      $flag = 1;
    }
    if($month){
      $monthFlag = 1;
    }

}

try {

  $db = new PDO(PDO_DSN,DB_USERNAME,DB_PASSWORD);
  $db->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

  if($flag == 1){
    //1月から月までの給料を取得

    $stmt1 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-01%'");
    $result1 = $stmt1->fetchAll(PDO::FETCH_ASSOC);
    $stmt2 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-02%'");
    $result2 = $stmt2->fetchAll(PDO::FETCH_ASSOC);
    $stmt3 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-03%'");
    $result3 = $stmt3->fetchAll(PDO::FETCH_ASSOC);
    $stmt4 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-04%'");
    $result4 = $stmt4->fetchAll(PDO::FETCH_ASSOC);
    $stmt5 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-05%'");
    $result5 = $stmt5->fetchAll(PDO::FETCH_ASSOC);
    $stmt6 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-06%'");
    $result6 = $stmt6->fetchAll(PDO::FETCH_ASSOC);
    $stmt7 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-07%'");
    $result7 = $stmt7->fetchAll(PDO::FETCH_ASSOC);
    $stmt8 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-08%'");
    $result8 = $stmt8->fetchAll(PDO::FETCH_ASSOC);
    $stmt9 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-09%'");
    $result9 = $stmt9->fetchAll(PDO::FETCH_ASSOC);
    $stmt10 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-10%'");
    $result10 = $stmt10->fetchAll(PDO::FETCH_ASSOC);
    $stmt11 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-11%'");
    $result11 = $stmt11->fetchAll(PDO::FETCH_ASSOC);
    $stmt12 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-12%'");
    $result12 = $stmt12->fetchAll(PDO::FETCH_ASSOC);

    $sum[0] = getsum($result1);
    $sum[1] = getsum($result2);
    $sum[2] = getsum($result3);
    $sum[3] = getsum($result4);
    $sum[4] = getsum($result5);
    $sum[5] = getsum($result6);
    $sum[6] = getsum($result7);
    $sum[7] = getsum($result8);
    $sum[8] = getsum($result9);
    $sum[9] = getsum($result10);
    $sum[10] = getsum($result11);
    $sum[11] = getsum($result12);

    //$month月のデータを取得
    if($monthFlag == 1){
      if($month < 10)
        $stmt13 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-0".$month."%'");
      else if($month >= 10)
        $stmt13 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-".$month."%'");

      $earn = $stmt13->fetchAll(PDO::FETCH_ASSOC);
      if(!empty($earn)){
        foreach ($earn as $a) {
          foreach($a as $key => $value){
            $wages[] = (int)$value;
            // var_dump((int)$value);
          }
        }
        // echo "賃金";
        // print_r($wages);

      //要求された月の日付を取得
        if($month < 10)
          $stmt14 = $db->query("select date from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-0".$month."%'");
        else if($month >= 10)
          $stmt14 = $db->query("select date from i12031earns where name = '".$_SESSION["USERID"]."' and date like '".$year."-".$month."%'");

        $date = $stmt14->fetchAll(PDO::FETCH_ASSOC);
        foreach ($date as $a) {
          foreach($a as $key => $value){
            $temp = explode("-",$value);
            //echo $temp[2];
            $requireDate[] = (int)$temp[2];
          }
        }
        // echo "日付";
        // print_r($requireDate);
        //変数は全てint型で入っています
        //かぶっている日をは合計してしまえ

        for($i = 0;$i < count($requireDate)-1;$i++){
          $tempDate = $requireDate[$i];
          for($j = $i+1; $j < count($requireDate); $j++){
            if($tempDate == $requireDate[$j]){
              $requireDate[$j] = 0;
              $wages[$i] = $wages[$i]+$wages[$j];
              $wages[$j] = 0;
            }
          }
        }
        // print_r($wages);
        // print_r($requireDate);

        //正規化
        for($i = 1;$i <= 31 ;$i++){
          $newWages[$i] = 0;
          for($j = 0; $j < count($requireDate); $j++){
            if($requireDate[$j] == $i){
              $newWages[$i] = $wages[$j];
            }
          }
        }
        // echo "正規化後";
        // print_r($newWages);

      }
      if(empty($earn))
        $monthFlag = 0;
    }
    if($deleteDate){
      $stmt18 = $db->prepare("DELETE FROM i12031earns WHERE name = '".$_SESSION["USERID"]."' and date = '".$deleteDate."'");
      $stmt18->execute();
    }

  }
  // $sumをjson形式に変換
  // $json = json_encode($sum);
  $s = implode(',', $sum);
  if($monthFlag == 1)
    $w = implode(',', $newWages);


    //表から今まで入力したデータを取り出す
    $stmt15 = $db->query("select workname from i12031earns where name = '".$_SESSION["USERID"]."'");
    $workname = $stmt15->fetchAll(PDO::FETCH_ASSOC);
    $stmt16 = $db->query("select earn from i12031earns where name = '".$_SESSION["USERID"]."'");
    $earn = $stmt16->fetchAll(PDO::FETCH_ASSOC);
    $stmt17 = $db->query("select date from i12031earns where name = '".$_SESSION["USERID"]."'");
    $date = $stmt17->fetchAll(PDO::FETCH_ASSOC);

    $newWorkname = getArranged($workname);
    $newEarn = getArranged($earn);
    $newDate = getArranged($date);
    // print_r($newWorkname);
    // print_r($newEarn);
    // print_r($newDate);


} catch (PDOException $e) {
    echo $e->getMessage();
    exit();
}

function getsum($result){
  $sum = 0;
  foreach ($result as $a) {
    foreach($a as $key => $value){
      $sum += (int)$value;
    }
  }
  return $sum;
}
function getArranged($array){
  foreach ($array as $a) {
    foreach($a as $key => $value){
      $result[] = $value;
    }
  }
  return $result;
}
?>


<!DOCTYPE html>
<html lang = "ja">
  <head>
    <meta charset="UTF-8">
    <title>result</title>
    <link rel="stylesheet" href="part_time_result.css">
    <!--Load the AJAX API-->
    <script type="text/javascript" src="https://www.google.com/jsapi"></script>



    <script type="text/javascript">



      // Load the Visualization API and the piechart package.
      google.load('visualization', '1.0', {'packages':['corechart']});

      // Set a callback to run when the Google Visualization API is loaded.
      google.setOnLoadCallback(drawChart);

      // Callback that creates and populates a data table,
      // instantiates the pie chart, passes in the data and
      // draws it.
      function drawChart() {
        var s = '<?php echo $s; ?>';
        var str = s.split(',');

        var num = new Array(12);
        for(var i = 0;i < str.length ;i++){
          num[i] = Number(str[i]);
        }

        // Create the data table.
        var data = new google.visualization.DataTable();
        data.addColumn('string', 'Topping');
        data.addColumn('number', 'Slices');
        data.addRows([
          ['January', num[0]],
          ['February', num[1]],
          ['March', num[2]],
          ['April', num[3]],
          ['May', num[4]],
          ['Jun', num[5]],
          ['July', num[6]],
          ['August', num[7]],
          ['September', num[8]],
          ['October', num[9]],
          ['November', num[10]],
          ['December', num[11]]

        ]);

        var year = '<?php echo $year; ?>';
        // Set chart options
        var options = {'title':'How Much Money I earned in '+year,
                       'width':600,
                       'height':400};

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.PieChart(document.getElementById('chart_div'));
        chart.draw(data, options);
      }

    </script>

    <script language="javascript" type="text/javascript" src="jquery-1.7.1.min.js"></script>
   <!--[if lt IE 9]>
       <script language="javascript" type="text/javascript" src="excanvas.min.js"></script>
   <![endif]-->
   <script language="javascript" type="text/javascript" src="jquery.jqplot.min.js"></script>
   <link rel="stylesheet" type="text/css" href="jquery.jqplot.min.css" />

   <script>
   var s = '<?php echo $s; ?>';
   var str = s.split(',');

   var num = new Array(12);
   for(var i = 0;i < str.length ;i++){
     num[i] = Number(str[i]);
   }

   jQuery( function() {
     jQuery . jqplot(
         'jqPlot-sample',
         [
             [ [ 1, num[0] ], [ 2, num[1] ], [ 3, num[2] ], [ 4, num[3] ], [ 5, num[4]], [ 6, num[5]], [ 7, num[6]], [ 8, num[7]], [ 9, num[8]], [ 10, num[9]], [ 11, num[10]], [ 12, num[11]] ]
         ],
         {
             title: '月別給料グラフ',
         }
     );
 } );
   </script>
   <script>
   var s1 = '<?php echo $w; ?>';
   var str1 = s1.split(',');

   var month = '<?php echo $month; ?>';

   var num1 = new Array(12);
   for(var i = 0;i < str1.length ;i++){
     num1[i] = Number(str1[i]);
   }

   jQuery( function() {
     jQuery . jqplot(
         'jqPlot-days',
         [
             [ [ 1, num1[0] ], [ 2, num1[1] ], [ 3, num1[2] ], [ 4, num1[3] ], [ 5, num1[4]], [ 6, num1[5]], [ 7, num1[6]], [ 8, num1[7]], [ 9, num1[8]], [ 10, num1[9]],
               [ 11, num1[10]], [ 12, num1[11]], [ 13, num1[12]], [ 14, num1[13]], [ 15, num1[14]], [ 16, num1[15]], [ 17, num1[16]], [ 18, num1[17]], [ 19, num1[18]], [ 20, num1[19]]
             , [ 21, num1[20]], [ 22, num1[21]], [ 23, num1[22]], [ 24, num1[23]], [ 25, num1[24]], [ 26, num1[25]], [ 27, num1[26]], [ 28, num1[27]], [ 29, num1[28]], [ 30, num1[29]]
           , [ 31, num1[30]] ]
         ],
         {
             title: month+'月の日別給料グラフ',
         }
     );
 } );
   </script>

  </head>
  <body>
    <div id="contents">
      <div id="header-fixed">
             <div id="header-bk">
                    <div id="header">バイト代計算サイト</div>
             </div>
      </div>
      <div id="body-bk">
             <div id="body">



  <div class="cont">
    <ul id="menu">

      <li><a href="part_time_cul.php">ホーム</a></li>
       <li><a href="part_time_result.php">これまでのバイト履歴</a></li>

      <li><a href="part_time_log.php"<?php //isset($_SESSION["USERID"]);$_SESSION = array();@session_destroy();?>>ログイン</a></li>

      <li><a href="part_time_logout.php">ログアウト</a></li>

    </ul>
    <br>
    <h1><?=htmlspecialchars($_SESSION["USERID"], ENT_QUOTES); ?>さんのバイト履歴</h1>
    <form id="loginForm" name="loginForm" action="" method="POST">
      <fieldset>
        <legend>年を選択</legend>

        <select name="year">
          <?php
            for($i = 2000 ; $i < $todays[0]+50 ; $i++){
              if($i == $todays[0])
                echo '<option value="'.$i.'" selected="">'.$i.'</option>';
              else
                  echo '<option value="'.$i.'">'.$i.'</option>';
            }
          ?>
          </select>
          年
          <SELECT name="month">
          <option value="">--</option>
          <option value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
          <option value="11">11</option>
          <option value="12">12</option>
          </SELECT>
          月
        <input type="submit" id="login" name="login" value="見る">
      </fieldset>

    <br>
  </div>

  <div class="cont">
    <!-- //googleCharts -->
    <div id="chart_div"></div>
  </div>

    <!-- jQuery -->

      <div id="jqPlot-sample" style="height: 400px; width: 400px; margin: 0 auto; "></div>
    <?php
      if($monthFlag == 1)
        echo '<div id="jqPlot-days" style="height: 400px; width: 900px; margin: 0 auto; "></div>';
    ?>
    <!-- table -->
  <div class="cont">
    <table class="bordered">
      <thead>
      <?php echo '<tr><th></th><th>'.$year.'年</th><th></th></tr>' ?>
      <tr>
          <th>月</th>
          <th>　　合計金額　（円）　</th>
          <th>total</th>
      </tr>
      </thead>
      <?php
        $total = 0;

        for($i = 0; $i<12;$i++){
          $total += $sum[$i];
          echo '<tr><td>'.($i+1).'</td><td>'.$sum[$i].'</td><td>'.$total.'</td></tr>';
        }
        echo '<tr><td>　</td><td>合計</td><td>'.$total.'　円</td></tr>';
      ?>



    </table>
    <br>
    <table class="bordered">
      <thead>
      <?php echo '<tr><th></th><th>'.$_SESSION["USERID"].'さんの今までのデータ（全部）</th><th></th></tr>' ?>
      <tr>
          <th>日付</th>
          <th>バイト名</th>
          <th>　　給料　（円）　</th>
      </tr>
      </thead>
      <?php
        for($i = 0; $i<count($newDate);$i++){
          echo '<tr><td>'.$newDate[$i].'</td><td>'.$newWorkname[$i].'</td><td>'.$newEarn[$i].'</td></tr>';
        }

      ?>
    </table>
    <!-- 削除 -->
      <p>＜選択した日付を削除 例: 2016-02-04＞</p>
      バイト名: <input type="text" name = "deleteDate">
      <input type="submit" value="削除する"
      onmouseover="this.value='削除する！！'" onmouseout="this.value='削除する'">
    </form>

    <ul>
    <li><a href="part_time_cul.php">戻る</a></li>
    </ul>
  </div>

            </div>
              </div>
              <div id="footer-fixed">
                <div id="footer-bk">
                    <div id="footer">
                      <p>made by : Hayate Nakayama</p>
                      <p>Copyright © National institue of Technology, Yuge Collage - I4 - hayatengu</p>
                    </div>
                </div>
              </div>


  </div>
  </body>
</html>
