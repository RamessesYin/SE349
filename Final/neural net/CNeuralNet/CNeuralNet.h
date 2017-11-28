#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

//神经细胞单元 
struct SNeuron
{
	int m_NumInputs; //进入神经细胞的输入个数
	vector<double>m_vecWeight;//每一个输入的权重值 
	
	SNeuron(int NumInputs); //构造函数 
};


//神经细胞层
struct SNeuronLayer
{
	int m_NumNeurons;
	vector<SNeuron> m_vecNeurons;
	
	SNeuronLayer(int NumNeurons, int NumInputsPerNueron);
};



struct CNeuralNet
{
private:
	int m_NumInputs;
	int m_NumOutputs;	
	int m_NumHiddenLayers; //这里的隐藏层包含输入层和所有隐藏层。通常隐藏层数为1 
	int m_NeuronsPerHiddenLayer;	
	double m_learnlevel;//学习率
	vector<SNeuronLayer>m_vecLayers;//神经网络中包含的所有层 
	
public:
	CNeuralNet(int NumInputs,int NumOutpts, int NumHdLyrs, int NeurinPHDLyrs, double LearnLevel); 	
	void CreateNet();//Create用于构造函数之中，用来创建整个神经网络 	
	int GetNumberofNeurons()const;//返回网络中神经元的总数	
	vector<double>GetErr()const;//返回网络中神经元的偏移值	
	void PutErr(vector<double>&err);//用新的偏移值代替原有偏移值	
	int GetNumberofWeights()const;//返回网络权重的总数	
	vector<double>GetWeights()const;//从神经网络中读出权重	
	void PutWeights(vector<double>&weights);//用新的权重代替原有权重	
	void FeedForward(vector<double>&inputs_Tj);//前馈以更新权重值	
	inline double Sigmoid(double activation, double response);//s型响应曲线
	vector<double>Update(vector<double>&inputs);	//根据输入来计算输出
	 
};






