/**
 * Created by Ramesses on 2017/6/17
 */

'use strict';

//是否为生产环境
var ENV={
    PROD : 0
};

var PROJECT='edit';

var app = angular.module(PROJECT, ['ui.router']);



//定义有关url的常量
app.constant("URL", {
    "BASE"   : "/",
    "REQUEST": "http://192.168.1.102:8080/",
});

//定义有关请求状态的常量
app.constant("REQUEST", {
    "UPDATE"   : {SUCCESS:'200'}
});

//http://202.120.39.166:8085/VideoInfo/qimei/testOnline/img/img-play.png

app.config(function($stateProvider, $urlRouterProvider){

    $urlRouterProvider.otherwise('/');

    $stateProvider
        .state('home', {
            url: '/home',
            templateUrl: 'partials/home.html',
            controller: 'HomeCtrl as home',
            onEnter: function($rootScope,URL){
                $rootScope.pageName='home';
            },
            onExit: function($rootScope){
                $rootScope.pageName='';
            }
        });
});


app.run(['$state', function($state,$rootScope){
    $state.go('home');
}]);


var DEBUG=true;

function log(msg)
{
    if(DEBUG)
    {
        console.log(msg);
    }
}

function prompt(p)
{
    alert(p);
}

function getRandom(min , max)
{
    var range=max-min;
    var rand=Math.random();
    return (min+Math.round(rand*range));
}


function sleep(n) {
    var start = new Date().getTime();
    while(true)  if(new Date().getTime()-start > n) break;
}



