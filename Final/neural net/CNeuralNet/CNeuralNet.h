#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

//��ϸ����Ԫ 
struct SNeuron
{
	int m_NumInputs; //������ϸ�����������
	vector<double>m_vecWeight;//ÿһ�������Ȩ��ֵ 
	
	SNeuron(int NumInputs); //���캯�� 
};


//��ϸ����
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
	int m_NumHiddenLayers; //��������ز�����������������ز㡣ͨ�����ز���Ϊ1 
	int m_NeuronsPerHiddenLayer;	
	double m_learnlevel;//ѧϰ��
	vector<SNeuronLayer>m_vecLayers;//�������а��������в� 
	
public:
	CNeuralNet(int NumInputs,int NumOutpts, int NumHdLyrs, int NeurinPHDLyrs, double LearnLevel); 	
	void CreateNet();//Create���ڹ��캯��֮�У������������������� 	
	int GetNumberofNeurons()const;//������������Ԫ������	
	vector<double>GetErr()const;//������������Ԫ��ƫ��ֵ	
	void PutErr(vector<double>&err);//���µ�ƫ��ֵ����ԭ��ƫ��ֵ	
	int GetNumberofWeights()const;//��������Ȩ�ص�����	
	vector<double>GetWeights()const;//���������ж���Ȩ��	
	void PutWeights(vector<double>&weights);//���µ�Ȩ�ش���ԭ��Ȩ��	
	void FeedForward(vector<double>&inputs_Tj);//ǰ���Ը���Ȩ��ֵ	
	inline double Sigmoid(double activation, double response);//s����Ӧ����
	vector<double>Update(vector<double>&inputs);	//�����������������
	 
};






