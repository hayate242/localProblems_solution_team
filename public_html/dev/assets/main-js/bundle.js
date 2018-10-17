var chart;(chart=new CanvasJS.Chart("columnChartContainer",{theme:"light1",animationEnabled:!1,title:{text:"棒グラフ"},data:[{type:"column",dataPoints:[{label:"apple",y:10},{label:"orange",y:15},{label:"banana",y:25},{label:"mango",y:30},{label:"grape",y:28}]}]})).render();for(var limit=1e3,y=0,data=[],dataSeries={type:"line"},dataPoints=[],i=0;i<limit;i+=1)y+=10*Math.random()-5,dataPoints.push({x:i-limit/2,y:y});dataSeries.dataPoints=dataPoints,data.push(dataSeries),(chart=new CanvasJS.Chart("lineChartContainer",{animationEnabled:!0,zoomEnabled:!0,title:{text:"折れ線グラフ"},axisY:{includeZero:!1},data:data})).render();
var chart = new CanvasJS.Chart("mixChartContainer", {
	animationEnabled: true,
	theme: "light2",
	title: {
		text: "月別xxxデータ"
	},
	axisX: {
		valueFormatString: "MMM"
	},
	axisY: {
		prefix: "",
		labelFormatter: addSymbols
	},
	toolTip: {
		shared: true
	},
	legend: {
		cursor: "pointer",
		itemclick: toggleDataSeries
	},
	data: [
	{
		type: "column",
		name: "実際の量",
		showInLegend: true,
		xValueFormatString: "MMMM YYYY",
		yValueFormatString: "#,##0",
		dataPoints: [
			{ x: new Date(2018, 0), y: 20000 },
			{ x: new Date(2018, 1), y: 30000 },
			{ x: new Date(2018, 2), y: 25000 },
			{ x: new Date(2018, 3), y: 70000, indexLabel: "High Renewals" },
			{ x: new Date(2018, 4), y: 50000 },
			{ x: new Date(2018, 5), y: 35000 },
			{ x: new Date(2018, 6), y: 30000 },
			{ x: new Date(2018, 7), y: 43000 },
			{ x: new Date(2018, 8), y: 35000 },
			{ x: new Date(2018, 9), y:  30000},
			{ x: new Date(2018, 10), y: 40000 },
			{ x: new Date(2018, 11), y: 50000 }
		]
	}, 
	{
		type: "line",
		name: "予想量",
		showInLegend: true,
		yValueFormatString: "#,##0",
		dataPoints: [
			{ x: new Date(2018, 0), y: 40000 },
			{ x: new Date(2018, 1), y: 42000 },
			{ x: new Date(2018, 2), y: 45000 },
			{ x: new Date(2018, 3), y: 45000 },
			{ x: new Date(2018, 4), y: 47000 },
			{ x: new Date(2018, 5), y: 43000 },
			{ x: new Date(2018, 6), y: 42000 },
			{ x: new Date(2018, 7), y: 43000 },
			{ x: new Date(2018, 8), y: 41000 },
			{ x: new Date(2018, 9), y: 45000 },
			{ x: new Date(2018, 10), y: 42000 },
			{ x: new Date(2018, 11), y: 50000 }
		]
	},
	{
		type: "area",
		name: "xxxx",
		markerBorderColor: "white",
		markerBorderThickness: 2,
		showInLegend: true,
		yValueFormatString: "#,##0",
		dataPoints: [
			{ x: new Date(2018, 0), y: 5000 },
			{ x: new Date(2018, 1), y: 7000 },
			{ x: new Date(2018, 2), y: 6000},
			{ x: new Date(2018, 3), y: 30000 },
			{ x: new Date(2018, 4), y: 20000 },
			{ x: new Date(2018, 5), y: 15000 },
			{ x: new Date(2018, 6), y: 13000 },
			{ x: new Date(2018, 7), y: 20000 },
			{ x: new Date(2018, 8), y: 15000 },
			{ x: new Date(2018, 9), y:  10000},
			{ x: new Date(2018, 10), y: 19000 },
			{ x: new Date(2018, 11), y: 22000 }
		]
	}]
});
chart.render();

function addSymbols(e) {
	var suffixes = ["", "K", "M", "B"];
	var order = Math.max(Math.floor(Math.log(e.value) / Math.log(1000)), 0);

	if(order > suffixes.length - 1)                	
		order = suffixes.length - 1;

	var suffix = suffixes[order];      
	return CanvasJS.formatNumber(e.value / Math.pow(1000, order)) + suffix;
}

function toggleDataSeries(e) {
	if (typeof (e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
		e.dataSeries.visible = false;
	} else {
		e.dataSeries.visible = true;
	}
	e.chart.render();
}

var chart = new CanvasJS.Chart("pieChartContainer", {
	animationEnabled: true,
	title: {
		text: "Desktop Search Engine Market Share - 2016"
	},
	data: [{
		type: "pie",
		startAngle: 240,
		yValueFormatString: "##0.00\"%\"",
		indexLabel: "{label} {y}",
		dataPoints: [
			{y: 79.45, label: "Google"},
			{y: 7.31, label: "Bing"},
			{y: 7.06, label: "Baidu"},
			{y: 4.91, label: "Yahoo"},
			{y: 1.26, label: "Others"}
		]
	}]
});
chart.render();