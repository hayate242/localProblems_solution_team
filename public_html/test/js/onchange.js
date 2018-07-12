$(function() {
 
    //セレクトボックスが切り替わったら発動
    $('select').change(function() {
   
      //選択したvalue値を変数に格納
      var val = $('.selected_year').val() + $('.selected_month').val() + $('.selected_day').val();
      var date = $('.selected_year').val() + "/" + $('.selected_month').val() + "/" + $('.selected_day').val();
      //選択したvalue値をp要素に出力
      $('.test').text(date+"のグラフ");
      loadCSV('data/'+ val + '.csv');
    });
  });