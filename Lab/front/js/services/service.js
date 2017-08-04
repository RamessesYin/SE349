/**
 * Created by Ramesses on 2017/6/17
 */
var app=angular.module(PROJECT);



/**
 * 统一restful api请求
* */

app.factory('RESTClient', ['$http', '$q', function($http, $q){
    var self=

    {

        responseCode:0,

        getResource: function(url,data){
            var defer = $q.defer();
            var str='';
            for(var p in data)
            {
                str+=(p+'='+data[p]+"&");
            }
            if(str!='')
            {
                str.substring(0,str.length-1);
                str='?'+str;
            }
            $http.get(url+str)
            .then(function(res){
                defer.resolve(res.data);
            }, function(res){
                defer.reject(res.data);
            });
            return defer.promise;
        },


        addResource: function(url, data){
            var defer = $q.defer();
            $http.post(url,data)
                .then(function(res){
                    defer.resolve(res.data);
                }, function(res){
                    defer.reject(res.data);
                });
            return defer.promise;
        },

        deleteResource: function(url){
            var defer = $q.defer();
            $http.delete(url)
            .then(function(res){
                defer.resolve(res.data);
            }, function(res){
                defer.reject(res.data);
            });
            return defer.promise;
        },

        deleteDataResource: function(url,data){
            var defer = $q.defer();
            $http.delete(url,{
                data:data
            })
            .then(function(res){
                defer.resolve(res.data);
            }, function(res){
                defer.reject(res.data);
            });
            return defer.promise;
        },


        updateResource: function(url, data){
            var defer = $q.defer();
            $http.put(url,data)
            .then(function(res){
                log(res);
                
                defer.resolve(res.data);
            }, function(res){
                defer.reject(res.data);
            });
            return defer.promise;
        }

    }

    return self;

}]);



app.factory('Names',function(RESTClient,URL){

    var self={};
    self.namelist=[];







    return self;

});

