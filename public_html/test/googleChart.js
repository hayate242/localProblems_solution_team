

var username;
var jobName = [];
var date = [];
var wage = [];

var num = new Array(12);
function getdata(){
    if(window.location.search){
        /* URLの「?」以降のパラメータを変数nに代入 */
        var n=window.location.search.substring(1,window.location.search.length);
        /* テキストボックスにパラメータを表示 */
      // document.form3.elements["getpram"].value=n;
                        username = n.replace("name=","");
                        console.log(username);
    }
}
/* オンロード時に実行 */
window.onload=getdata;

function loadHtml(fileName){
    var cnt = 0;

  httpObj = new XMLHttpRequest();
  httpObj.open('GET',fileName+"?"+(new Date()).getTime(),true);
  // ?以降はキャッシュされたファイルではなく、毎回読み込むためのもの
  httpObj.send(null);
  httpObj.onreadystatechange = function(){
      if ( (httpObj.readyState == 4) && (httpObj.status == 200) ){
          paths = httpObj.responseText.split(",");
        
      var out = "";
      for (n = 0; n < paths.length; n++) {
        paths[n] = paths[n].replace(/\r?\n/g,"");
        paths[n] = paths[n].replace(" ","");
        //ユーザ名と等しいならデータ追加
        if(paths[n] == username){
            console.log("おなじ！！！");
            jobName[cnt] = paths[n+1];
            date[cnt] = paths[n+2].replace("/","<");
            date[cnt] = date[cnt].replace("/",">");
            wage[cnt] = Number(paths[n+3]);
            //console.log(typeof wage[cnt]);

            out += wage[cnt] ;
            //console.log(jobName[cnt]);
            //console.log(date[cnt]);
            //console.log(wage[cnt]);
            n += 3;
            cnt++;
        }
        //out +=  paths[n] + "\n";
        //document.write(paths[n]+'<br>');
      }



//データを月別で分ける
var only_months = [];

for (n = 0; n < date.length; n++) {
    //console.log(n);
    //console.log(date[n]);
    only_months[n] = date[n].match(/<(.*?)>/g);
    //console.log( "only_months = " + only_months[n] );
}

for(n = 0; n < num.length; n++){
    num[n] = 0;
    //console.log("num["+n+"] = "+num[n]);
}

for(n = 0; n < date.length; n++){
    if(only_months[n] == "<1>"){
        num[0] += wage[n];
    }
    else if(only_months[n] == "<2>"){
        num[1] += wage[n];
    }
    else if(only_months[n] == "<3>"){
        num[2] += wage[n];
    }
    else if(only_months[n] == "<4>"){
        num[3] += wage[n];
    }
    else if(only_months[n] == "<5>"){
        num[4] += wage[n];
    }
    else if(only_months[n] == "<6>"){
        num[5] += wage[n];
    }
    else if(only_months[n] == "<7>"){
        num[6] += wage[n];
    }
    else if(only_months[n] == "<8>"){
        num[7] += wage[n];
    }
    else if(only_months[n] == "<9>"){
        num[8] += wage[n];
    }
    else if(only_months[n] == "<10>"){
        num[9] += wage[n];
    }
    else if(only_months[n] == "<11>"){
        num[10] += wage[n];
    }
    else if(only_months[n] == "<12>"){
        num[11] += wage[n];
    }
}

for(n = 0; n < num.length; n++){
    //console.log("num ["+n+"] "+num[n]);
}		


  document.getElementById("out").innerHTML = out;
}
}

// Load the Visualization API and the corechart package.
google.charts.load('current', {'packages':['corechart']});

// Set a callback to run when the Google Visualization API is loaded.
google.charts.setOnLoadCallback(drawChart);

// Callback that creates and populates a data table,
// instantiates the pie chart, passes in the data and
// draws it.
function drawChart() {

// Create the data table.
var data = new google.visualization.DataTable();
data.addColumn('string', 'Months');
data.addColumn('number', 'Wage');
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

// Set chart options
var options = {'title':'月別バイト代',
               'width':400,
               'height':300};

// Instantiate and draw our chart, passing in some options.
var chart = new google.visualization.PieChart(document.getElementById('chart_div'));
chart.draw(data, options);
}

}



