//本日の日付を取得する
$time = time();
$year = date("Y", $time);
$month = date("n", $time);
$day = date("j", $time);
 
print("<select name=\"year\">");
 
//年は修正してください
for( $i = 2005; $i <= 2010; $i++ ){
  if( $i == $year ){
    print("<option value=\"$i\" selected>$i</option>");
  }else{
    print("<option value=\"$i\">$i</option>");
  }
}
 
print("</select>年");
print("<select name=\"month\">");
 
for( $j = 1; $j <= 12; $j++ ){
  if( $j == $month ){
    print("<option value=\"$j\" selected>$j</option>");
  }else{
    print("<option value=\"$j\">$j</option>");
  }
}
print("</select>月");
print("<select name=\"day\">");
 
for( $k = 1; $k <=31 ; $k++ ){
  if( $k == $day ){
    print("<option value=\"$k\" selected>$k</option>");
  }else{
    print("<option value=\"$k\">$k</option>");
  }
}
print("</select>日");