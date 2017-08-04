/**
 * Created by Ramesses on 2017/6/17
 */


var app = angular.module(PROJECT);


app.controller('NavbarCtrl',function($scope,$rootScope,$state)
{
  $scope.change=function()
  {
  	if($rootScope.pageName=='brief')
  	{
  		$state.go('home');  
  	}
  	else 
  	{
  		$state.go('brief'); 

  	}
  }
});


