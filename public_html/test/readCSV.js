// ---------------------------------------------------------------
//  readCSV.js
//
//                  Mar/30/2018
//
// ---------------------------------------------------------------

var layout = {
    title:''
};
let DATANUM = 6;
// let DATANUM = 7; // for avoiding read csv :MAINDATA:?
// responded data
var res = [];
var updateFlag = false;
var chart_data = {
    x: [],
    y: [],
    type: 'scatter',
    name: 'Direct current'
}
function Info(_Time, _Func, _Err, _Type, _Value, _TimeStamp) {
    this.time = _Time,
    this.func = _Func;
    this.err = _Err;
    this.type = _Type;
    this.value = _Value;
    this.timeStamp = _TimeStamp;
}

function parseData(_paths){
    for (n = 0; n < paths.length ; n += DATANUM) {
        res[n/DATANUM] = new Info(_paths[n], _paths[n+1], _paths[n+2], _paths[n+3], _paths[n+4], _paths[n+5]);
    }
    
    // for avoiding read csv :MAINDATA:?
    // for (n = 0; n < paths.length ; n += DATANUM) {
    //     res[n/DATANUM] = new Info(_paths[n+1], _paths[n+2], _paths[n+3], _paths[n+4], _paths[n+5], _paths[n+6]);
    // }
    res.pop();
    // replace value format to display on chart
    // for( i = 0; i < res.length; i++ ){
        
    // }
    console.log(res);
}

function make_chart_data(){
    // init
    chart_data.x = []
    chart_data.y = []
    for( i = 0; i < res.length; i++ ){
        chart_data.x.push(res[i].time);
        // chart_data.x.push(i);
        chart_data.y.push( Number(res[i].value) );
    }
    console.log(chart_data);
}

function plot_chart(){
    var data = [ chart_data, layout ];
    if( updateFlag == false ){
        Plotly.newPlot( 'chart_div', data );
        update_layout();
        updateFlag = true;
    }else {
        Plotly.react( 'chart_div', data );
        update_layout();
    }
}

function update_layout() {
    // update only values within nested objects
    var update = {
        title: '直流電流値グラフ', // updates the title
        'xaxis.title': '時刻',   // updates the xaxis range
        'yaxis.title': '電流値[A]'     // updates the end of the yaxis range
    };
    Plotly.relayout(chart_div, update)
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
            paths = httpObj.responseText.split(/\r?\n|,/);
            // console.log(paths);
            parseData(paths);
            make_chart_data();
            plot_chart();
        }
    }
}

// main
loadCSV('20180628.csv');
// var data = [ chart_data, options ];
// Plotly.newPlot( 'chart_div', data );

// ---------------------------------------------------------------