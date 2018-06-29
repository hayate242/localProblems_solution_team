// ---------------------------------------------------------------
//  readCSV.js
//
//                  Mar/30/2018
//
// ---------------------------------------------------------------
var trace1 = {
    x: [0,1,2,3,4,5],
    y: [3,10, 15, 13, 17,12],
    type: 'scatter'
}

var trace2 = {
    x: [0,1,2,3,4,5],
    y: [5,16, 5, 11, 9,8],
    type: 'scatter'
}

var trace3 = {
    x: [0,1,2,3,4,5],
    y: [7,10, 8, 12, 4,3],
    type: 'scatter'
}
var options = {
  title: 'サンプルチャート'
};
let DATANUM = 6;
// responded data
var res = [];
function Info(_Time, _Func, _Err, _Type, _Value, _TimeStamp) {
    this.time = _Time,
    this.func = _Func;
    this.err = _Err;
    this.type = _Type;
    this.value = _Value;
    this.timeStamp = _TimeStamp;
}

function parseData(_paths){
    var itterator = 0;
    for (n = 0; n < paths.length/DATANUM ; n += DATANUM) {
        res[n] = new Info(_paths[n], _paths[n+1], _paths[n+2], _paths[n+3], _paths[n+4], _paths[n+5]);
    }
    console.log(res);
}


function loadCSV(fileName){
    var cnt = 0;

    httpObj = new XMLHttpRequest();
    httpObj.open('GET',fileName+"?"+(new Date()).getTime(),true);
    // ?以降はキャッシュされたファイルではなく、毎回読み込むためのもの
    httpObj.send(null);
    httpObj.onreadystatechange = function(){
        if ( (httpObj.readyState == 4) && (httpObj.status == 200) ){
            httpObj.responseText.replace(/\r?\n/g,"");
            paths = httpObj.responseText.split(",");
            console.log(paths);
            parseData(paths);
        }
    }
}

var data = [trace1,trace2,trace3,options];
Plotly.newPlot('graph_content', data);

// ---------------------------------------------------------------