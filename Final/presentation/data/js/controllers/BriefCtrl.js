// /**
//  * Created by Ramesses on 2017/6/17
//  */
// var app = angular.module(PROJECT);


// app.controller('HomeCtrl',function($scope,$rootScope,$http,RESTClient,Names,$state,URL)
// {
//     var data={};       
//     var myChart=[];
//     var input_data=[];
//     var input_nodes=[];
//     var input_links=[];
//     var input_names={"full_name":[],"sim_name":[]};
//     $scope.selftags=[];
//     $scope.recom_tag=[];
//     var categories=[
//                 {
//                     name: '人物'
//                 },
//                 {
//                     name: '@关系'
//                 },
//                 {
//                     name:'转发关系'
//                 }
//             ];
//     var links=[];
//     var option={
//     "title" : {
//         "text": "关系展示",
//         "subtext": "展示图",
//         "x":"right",
//         "y":"bottom"
//     },
//     "tooltip" : {
//         "trigger": "item",
//         "formatter": "{a} : {b}"
//     },
//     "toolbox": {
//         "show" : "true",
//         "feature": {
//             "restore" : {"show": true},
//             "saveAsImage" : {"show": true}
//         }
//     },
//     "legend": {
//         "x": "left",
//         "data":["@关系","转发关系"]
//     },
//     "series" : [
//         {
//             "type":"force",
//             "name": "节点",
//             "ribbonType": true,
//             "categories": [],
//             "itemStyle": {
//                 "normal": {
//                     "label": {
//                         "show": true,
//                         "textStyle": {
//                             "color": "#333"
//                         }
//                     },
//                     "nodeStyle" : {
//                         "brushType" : "both",
//                         "borderColor" : "rgba(255,215,0,0.4)",
//                         "borderWidth" : 1
//                     },
//                     "linkStyle": {
//                         "type": "curve"
//                     }
//                 },
//                 "emphasis": {
//                     "label": {
//                         "show": false
//                     },
//                     "nodeStyle" : {
//                     },
//                     "linkStyle" : {}
//                 }
//             },
//             "useWorker": false,
//             "minRadius" : 10,
//             "maxRadius" : 30,
//             "gravity": 1.1,
//             "scaling": 1.1,
//             "roam": "move",
//             "nodes":[],
//             "links":[]
//         }
//     ]
// };
//     config=function()
//     {
//         require.config({
//             paths: {
//                 echarts: 'echarts/build/dist'
//             }
//         });
//     }
//     implement=function()
//     {
//                 require(
//             [
//                 'echarts',
//                 'echarts/chart/force' // 使用柱状图就加载bar模块，按需加载
//             ],
//             function (ec) {
//                 // 基于准备好的dom，初始化echarts图表
//                 myChart=ec.init(document.getElementById('main')); 
//                 option.series[0].nodes=input_nodes;
//                 option.series[0].links=input_links;
//                 option.series[0].categories=categories;
//                 myChart.setOption(option);
//                  window.onresize = function () {
//                      myChartContainer();
//                      myChart.resize();
//                 };
 
      
  
//             }
//         );

//     }



//     init=function()
//     {
//         // config();
//         // var name="----柠檬皮----";
//         // var prelink=[];
//         // input_nodes=[];
//         // input_links=[];
//         // RESTClient.getResource(URL.REQUEST+"getTagByName?name="+name)
//         //         .then(function(data)
//         //         {
//         //             var tags=data.tag;
//         //             $scope.recom_tag=data.recom_tag;
//         //             var pos=0;
//         //             while((pos=tags.indexOf(';'))!=-1)
//         //             {
//         //                 var newtag=tags.substring(0,pos);
//         //                 $scope.selftags.push(newtag);
//         //                 tags=tags.substring(pos+1);
//         //             }
//         //             console.log($scope.selftags);

        



//         //        }); 
//         // RESTClient.getResource(URL.REQUEST+"getPreInfoByName?name="+name)
//         // .then(function(data1)
//         // {
//         //     for(var i=0;i<data1.length;i++)
//         //     {
//         //         var node=data1[i].pre_person;

//         //         RESTClient.getResource(URL.REQUEST+"getPreInfoByName?name="+data1[i].pre_person)
//         //          .then(function(data2)
//         //         {
//         //             if(data2.length>0)
//         //             {
//         //             var tmp={};   
//         //             tmp.name=data2[0].name;          
//         //             tmp.links=[];
//         //             for(var j=0;j<data2.length;j++)
//         //             {
//         //                 tmp.links.push(data2[j].pre_person);                            
//         //             }
//         //             prelink.push(tmp);

//         //             }
//         //             else
//         //             {
//         //                 var tmp={};
//         //                 tmp.name=node;
//         //                 tmp.links=[];
//         //                 prelink.push(tmp);
//         //             }

                  
//         //          }); 
//         //     }
//         //     console.log("prelink");
//         //     console.log(prelink);
//         //     var atlink=[];
//         //     RESTClient.getResource(URL.REQUEST+"getAtInfoByName?name="+name)
//         //     .then(function(data1)
//         //     {
//         //             for(var i=0;i<data1.length;i++)
//         //          {
//         //             var tmp={};
//         //             tmp.node=data1[i].at_person;
//         //             tmp.value=data1[i].value;
//         //             atlink.push(tmp);
                
//         //     }
//         //     console.log("atlink");
//         //     console.log(atlink);

//         //     var host={"category":0, "name": name, "value" : 100, label: '主体'};
//         //     input_nodes.push(host);
//         //     for(var i=0;i<atlink.length;i++)
//         //     {
//         //         var node={"category":1, "name": atlink[i].node+'.', "value" : atlink[i].value*30, label:atlink[i].node};
//         //         input_nodes.push(node);
//         //         var link={"source" :name , "target" :atlink[i].node+'.', "weight" :atlink[i].value*30, "name":atlink[i].value};
//         //         input_links.push(link);

//         //     }
//         //     for(var i=0;i<prelink.length;i++)
//         //     {
//         //         var node={"category":2, "name": prelink[i].name+'..', "value" : 40, label: prelink[i].name};
//         //         var link={"source" :name , "target" :prelink[i].name+'..', "weight" :0, "name": "转发了TA"};
//         //         input_nodes.push(node);
//         //         input_links.push(link);
//         //         for(var j=0;j<prelink[i].links.length;j++)
//         //         {
//         //             var node={"category":2, "name": prelink[i].links[j]+i+'.'+j, "value" : 40, label:prelink[i].links[j]};
//         //             var link={"source" :prelink[i].name+".." , "target" :prelink[i].links[j]+i+'.'+j, "weight" :0, "name": "转发了TA"};
//         //             input_nodes.push(node);
//         //             input_links.push(link);

//         //         }

//         //     }
//         //     console.log("nodes&links");
//         //     console.log(input_nodes);
//         //     console.log(input_links);

//         //     implement();

//         //     }); 
//         // });

  

//     }
//     $scope.select=function()
//     {
//         $scope.recom_tag=[];
//         $scope.selftags=[];
//         config();
//         var name=$scope.selected;
//         var prelink=[];
//         input_nodes=[];
//         input_links=[];
//         RESTClient.getResource(URL.REQUEST+"getTagByName?name="+name)
//                 .then(function(data)
//                 {
//                     var tags=data.tag;
//                     var pos=0;
//                     if(tags)
//                     {
//                         while((pos=tags.indexOf(';'))!=-1)
//                     {
//                         var newtag=tags.substring(0,pos);
//                         $scope.selftags.push(newtag);
//                         tags=tags.substring(pos+1);
//                     }

//                     }

//                     console.log($scope.selftags);
//                     pos=0;
//                     tags=data.recom_tag;
//                     if(tags)
//                     {
//                         while((pos=tags.indexOf(';'))!=-1)
//                     {
//                         var newtag=tags.substring(0,pos);
//                         $scope.recom_tag.push(newtag);
//                         tags=tags.substring(pos+1);
//                     }

//                     }





        



//                }); 
//         RESTClient.getResource(URL.REQUEST+"getPreInfoByName?name="+name)
//         .then(function(data1)
//         {
//             for(var i=0;i<data1.length;i++)
//             {
//                 var node=data1[i].pre_person;

//                 RESTClient.getResource(URL.REQUEST+"getPreInfoByName?name="+data1[i].pre_person)
//                  .then(function(data2)
//                 {
//                     if(data2.length>0)
//                     {
//                     var tmp={};   
//                     tmp.name=data2[0].name;          
//                     tmp.links=[];
//                     for(var j=0;j<data2.length;j++)
//                     {
//                         tmp.links.push(data2[j].pre_person);                            
//                     }
//                     prelink.push(tmp);

//                     }
//                     else
//                     {
//                         var tmp={};
//                         tmp.name=node;
//                         tmp.links=[];
//                         prelink.push(tmp);
//                     }

                  
//                  }); 
//                  sleep(1000);
//             }
//             console.log("prelink");
//             console.log(prelink);
//             var atlink=[];
//             RESTClient.getResource(URL.REQUEST+"getAtInfoByName?name="+name)
//             .then(function(data1)
//             {
//                     for(var i=0;i<data1.length;i++)
//                  {
//                     var tmp={};
//                     tmp.node=data1[i].at_person;
//                     tmp.value=data1[i].value;
//                     atlink.push(tmp);
                
//             }
//             console.log("atlink");
//             console.log(atlink);

//             var host={"category":0, "name": name, "value" : 50, label: '主体'};
//             input_nodes.push(host);
//             for(var i=0;i<atlink.length;i++)
//             {
//                 var node={"category":1, "name": atlink[i].node+'.', "value" : atlink[i].value*30, label:atlink[i].node};
//                 input_nodes.push(node);
//                 var link={"source" :name , "target" :atlink[i].node+'.', "weight" :atlink[i].value*30, "name":atlink[i].value};
//                 input_links.push(link);

//             }
//             for(var i=0;i<prelink.length;i++)
//             {
//                 var node={"category":2, "name": prelink[i].name+'..', "value" : 20, label: prelink[i].name};
//                 var link={"source" :name , "target" :prelink[i].name+'..', "weight" :i*30, "name": "转发了TA"};
//                 input_nodes.push(node);
//                 input_links.push(link);
//                 for(var j=0;j<prelink[i].links.length;j++)
//                 {
//                     var node={"category":2, "name": prelink[i].links[j]+i+'.'+j, "value" : 20, label:prelink[i].links[j]};
//                     var link={"source" :prelink[i].name+".." , "target" :prelink[i].links[j]+i+'.'+j, "weight" :j*10+i*5, "name": "转发了TA"};
//                     input_nodes.push(node);
//                     input_links.push(link);

//                 }

//             }
//             console.log("nodes&links");
//             console.log(input_nodes);
//             console.log(input_links);

//             implement();

//             }); 
//         });









//     }



    
//     function changeSize(elem){
//         if(+elem.width > 350){
//             elem.width = "350";
//         }
//     }

//     $scope.date=new Date();    
//     setInterval(function(){  
//         $scope.$apply(function(){  
//             $scope.date=new Date();  
          
//     });  
//     },1000);

        
//     init();



// });
