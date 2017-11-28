#include "CNeuralNet.h"
using namespace std;

//����Ȩ��ֵ 
double GetRand()  
{  
    return 2.0 * rand() / RAND_MAX - 1.0;  
}



SNeuron::SNeuron(int NumInputs){
	m_NumInputs = NumInputs;
	for(int i=0;i< NumInputs; i++){
		m_vecWeight.push_back(GetRand());
	}
	//thetaƫ��ֵ
	m_vecWeight.push_back(GetRand());
} 



SNeuronLayer::SNeuronLayer(int NumNeurons, int NumInputsPerNueron){
	m_NumNeurons = NumNeurons;
	for(int i=0;i<NumNeurons;i++){
		m_vecNeurons.push_back(SNeuron(NumInputsPerNueron));
	}
}



double CNeuralNet::Sigmoid(double netinput, double response)
{
	return ( 1 / ( 1 + exp(-netinput / response)));
}

CNeuralNet::CNeuralNet(int NumInputs,int NumOutputs, int NumHdLyrs, int NeuronPHDLyrs, double LearnLevel){
	m_NumInputs = NumInputs;
	m_NumOutputs = NumOutputs;
	m_NumHiddenLayers = NumHdLyrs;
	m_NeuronsPerHiddenLayer = NeuronPHDLyrs;
	m_learnlevel = LearnLevel;
	CreateNet();
}

void CNeuralNet::CreateNet(){
	if(m_NumHiddenLayers > 0){
		//��һ�����ز㣨������Ϊ������input��С�� 
		m_vecLayers.push_back(SNeuronLayer(m_NeuronsPerHiddenLayer, m_NumInputs));
		//֮������ز� 
		for(int i=0;i<m_NumHiddenLayers-1;i++){
			m_vecLayers.push_back(SNeuronLayer(m_NeuronsPerHiddenLayer, m_NeuronsPerHiddenLayer));
		} 
		//�����
		m_vecLayers.push_back(SNeuronLayer(m_NumOutputs, m_NeuronsPerHiddenLayer));
	}
	else{
		m_vecLayers.push_back(SNeuronLayer(m_NumOutputs,  m_NumInputs));
	}

}

vector<double> CNeuralNet::Update(vector<double>&inputs){
	vector<double>outputs;
	int cWeight = 0;
	if(inputs.size()!=m_NumInputs){
		return outputs;
	}
	
	for(int i=0;i<m_NumHiddenLayers+1;i++){
		if(i>0){
			inputs = outputs;
		}
		outputs.clear();
		
		cWeight = 0;
		for(int j=0;j<m_vecLayers[i].m_NumNeurons;j++){
			double netinput = 0;
			int NumInputs = m_vecLayers[i].m_vecNeurons[j].m_NumInputs;
			

			//Ȩ�����
			for(int k=0;k<NumInputs;k++){
				netinput += m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k] * inputs[cWeight++];
			} 
			//������ƫ��ֵtheta
			netinput += m_vecLayers[i].m_vecNeurons[j].m_vecWeight[NumInputs]*(1);
			outputs.push_back(Sigmoid(netinput,1));
			cWeight = 0;
		}
	}
	return outputs;
}

vector<double> CNeuralNet::GetErr()const{
	vector<double>errs;
	for (int i = 0; i < m_NumHiddenLayers + 1; i++){
		for (int j = 0; j < m_vecLayers[i].m_NumNeurons; j++){
			int errid = m_vecLayers[i].m_vecNeurons[j].m_NumInputs;
			errs.push_back(m_vecLayers[i].m_vecNeurons[j].m_vecWeight[errid]);
		}
	}
	return errs;
}

int CNeuralNet::GetNumberofNeurons()const{
	vector<double>errs = GetErr();
	return errs.size();
}

void CNeuralNet::PutErr(vector<double>&err){
	int vec_itt = 0;
	for (int i = 0; i < m_NumHiddenLayers + 1; i++){
		for (int j = 0; j < m_vecLayers[i].m_NumNeurons; j++){
			m_vecLayers[i].m_vecNeurons[j].m_vecWeight[m_vecLayers[i].m_vecNeurons[j].m_NumInputs] = err[vec_itt++];
		}
	}
}

vector<double> CNeuralNet::GetWeights() const{
	vector<double>weights;
	for (int i = 0; i < m_NumHiddenLayers + 1; i++){
		for (int j = 0; j < m_vecLayers[i].m_NumNeurons; j++){
			for (int k = 0; k < m_vecLayers[i].m_vecNeurons[j].m_NumInputs; k++)
				weights.push_back(m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k]);
		}
	}
	return weights;
}

int CNeuralNet::GetNumberofWeights()const{
	vector<double>weights = GetWeights();
	return weights.size();
}

void CNeuralNet::PutWeights(vector<double>&weights){
	int vec_itt = 0;
	for (int i = 0; i < m_NumHiddenLayers + 1; i++){
		for (int j = 0; j < m_vecLayers[i].m_NumNeurons; j++){
			for (int k = 0; k < m_vecLayers[i].m_vecNeurons[j].m_NumInputs; k++)
				m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k] = weights[vec_itt++];
		}
	}
}

void CNeuralNet::FeedForward(vector<double>&inputs_Tj){
	vector<double>outputs;
	int cWeight = 0;
	int vec_itt = 0;
	//�������ѵ������������Ԥ�ڽ��
	int outputNueronNum = m_vecLayers[m_vecLayers.size() - 1].m_NumNeurons;
	if (inputs_Tj.size() != m_NumInputs + outputNueronNum){
		return;
	}
	//Ԥ��Ŀ��ֵTj����vector��
	vector<double>Tj;
	for (int i = m_NumInputs; i < m_NumInputs + outputNueronNum; i++){
		Tj.push_back(inputs_Tj[i]);
	}
	//�õ�δ����ǰ������Ȩ��ֵ
	vector<double>weights = GetWeights();
	//�õ�������Ԫ�ϵ�ƫ��ֵ
	vector<double>errs = GetErr();
	//�������ֵ	
	vector<double>Outputs;
	//����ֵ
	
	vector<double>inputs = inputs_Tj;
	while (inputs.size()!= m_NumInputs)
		inputs.pop_back();
	vector<double>Inputs = inputs;

	for (int i = 0; i<m_NumHiddenLayers + 1; i++){
		if (i>0){
			inputs = outputs;
		}
		outputs.clear();

		cWeight = 0;
		for (int j = 0; j<m_vecLayers[i].m_NumNeurons; j++){
			double netinput = 0;
			int NumInputs = m_vecLayers[i].m_vecNeurons[j].m_NumInputs;

			//Ȩ�����
			for (int k = 0; k<NumInputs; k++){
				netinput += m_vecLayers[i].m_vecNeurons[j].m_vecWeight[k] * inputs[cWeight++];
			}
			//������ƫ��ֵtheta
			netinput += m_vecLayers[i].m_vecNeurons[j].m_vecWeight[NumInputs] * (1);
			double output = Sigmoid(netinput, 1);
			outputs.push_back(output);
			Outputs.push_back(output);
			cWeight = 0;
		}
	}

	vector<double>NeurinErr = Outputs;
	int NueronSize = GetNumberofNeurons();
	//�����¼��һ��Ľ�����ܽ���ǰ��
    vector<double>PreResult;
	vector<double>PreResultTemp;
	int PreLayerNeuronNumber = 0;
	int PreLayerNeuronNumberTemp = 0;
	//��Ԥ��ֵerr�ļ��� ǰ��
	for (int i = m_NumHiddenLayers ; i >= 0; i--){
		if (i == m_NumHiddenLayers ){
			for (int j = m_vecLayers[i].m_NumNeurons -1 ; j >= 0; j--){
				double PreErr = NeurinErr[NueronSize-1-j];
				NeurinErr[NueronSize - 1 - j] = PreErr * (1 - PreErr) * (Tj[Tj.size()-1-j] - PreErr);
				PreResult.push_back(NeurinErr[NueronSize - 1 - j]);
				PreLayerNeuronNumber++;
			}
		}
		else{
			for (int j = m_vecLayers[i].m_NumNeurons -1; j >= 0; j--){
				double PreErr = NeurinErr[NueronSize - 1 - PreLayerNeuronNumber - j];
				for (int k = m_vecLayers[i + 1].m_NumNeurons - 1; k >= 0; k--){					
					NeurinErr[NueronSize - 1 - PreLayerNeuronNumber - j] = PreErr * (1 - PreErr) * PreResult[k] * m_vecLayers[i + 1].m_vecNeurons[k].m_vecWeight[m_vecLayers[i].m_NumNeurons - 1-j];
				}
				PreResultTemp.push_back(NeurinErr[NueronSize - 1 - PreLayerNeuronNumber - j]);
				PreLayerNeuronNumberTemp++;
			}
			PreLayerNeuronNumber += PreLayerNeuronNumberTemp;
			PreResult = PreResultTemp;
			PreResultTemp.clear();
			PreLayerNeuronNumberTemp = 0;
		}
	}

	//����Ȩ�ظ���
	for (int i = 0; i < Outputs.size() - 1; i++)
		Inputs.push_back(Outputs[i]);
	//�ȸ���ƫ��ֵ
	for (int i = 0; i < NeurinErr.size(); i++){
		errs[i] = errs[i] + m_learnlevel * NeurinErr[i];
	}
	PutErr(errs);

	int itt1 = 0;
	int itt2 = 0;
	int itt3 = 0;
	int tempitt = 0;
	for (int i = 0; i < m_NumHiddenLayers + 1; i++){
		for (int j = 0; j < m_vecLayers[i].m_NumNeurons; j++){
			for (int k = 0; k < m_vecLayers[i].m_vecNeurons[j].m_NumInputs; k++){
				weights[itt1] = weights[itt1] + m_learnlevel * Inputs[tempitt + itt3] * NeurinErr[itt2];
				itt1++;
				itt3++;
			}
			itt3 = 0;
			itt2++;			
		}
		tempitt += m_vecLayers[i].m_vecNeurons[0].m_NumInputs;
	}
	PutWeights(weights);

	return;
}