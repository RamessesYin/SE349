#include "CNeuralNet.h"
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//int main(){
//
//	CNeuralNet testNet= CNeuralNet(3,1,1,2,0.9);
//	//system("pause");
//	vector<double>inputs = { 0.3, 0.6, 0.1 ,0.0008};
//	vector<double>input = { 0.3, 0.6, 0.1 };
//	
//	for (int i = 0; i < 1000; i++){
//		testNet.FeedForward(inputs);
//	}
//	vector<double>outputs = testNet.Update(input);
//	for (int i = 0; i < outputs.size(); i++)
//		cout << outputs[i] << ' ';
//
//	system("pause");
//	return 0;
//}

void inline sort(vector<double>&v){
	if (v[0] > v[1]) swap(v[0], v[1]);
	if (v[1] > v[2]) swap(v[1], v[2]);
	if (v[0] > v[1]) swap(v[0], v[1]);
}
int main(int argc,char*argv[]){
	
	CNeuralNet testNet = CNeuralNet(3, 1, 1, 2, 0.9);
	ifstream ifs("C:/Users/DELL/Desktop/数据挖掘/input.csv");
	ifstream tfs("C:/Users/DELL/Desktop/数据挖掘/tags.csv");
	ifstream pfs("C:/Users/DELL/Desktop/数据挖掘/people.csv");
	ofstream ofs("C:/Users/DELL/Desktop/数据挖掘/out.csv");
	vector<string>tags;
	char buf[1024];
	while (tfs.getline(buf,1024)){
		string t = string(buf);
		tags.push_back(t);
	}
	//vector<double>input = { 0, 0, 0 };
	//for (int i = 0; i < 3 && i+1 < argc; i++){
	//	string s = string(argv[i + 1]);
	//	cout << s;
	//	for (int ii = 0; ii < tags.size();ii++){
	//		if (tags[ii] == s){
	//			input[i] = sqrt(ii / tags.size());
	//		}
	//	}
	//}

	for (int i = 0; i < 10000; i++){
		vector<double>inputs(4);
		ifs >> inputs[0] >> inputs[1] >> inputs[2] >> inputs[3];
		sort(inputs);
		testNet.FeedForward(inputs);
	}
	
	/*vector<double>input = { 0.8743634979916017, 0.6290148512649062, 0.2478411707651892 };
	vector<double>out = { 0.8743634979916017, 0.6290148512649062, 0.2478411707651892, 0.5981122213522563 };
	for (int i = 0; i < out.size(); i++){
		cout << tags[out[i] * out[i] * tags.size()];
	}
	cout << endl;
	sort(out);
	sort(input);
	vector<double>outputs = testNet.Update(input);
	for (int i = 0; i < outputs.size(); i++){
		cout << outputs[i] << ' ';
		cout << tags[outputs[i] * outputs[i] * tags.size()]<<endl;
	}
	system("pause");
	return 0;*/
	double t;
	while (pfs >> t){
		vector<double>input = { 0, 0, 0 };
		pfs >> input[1] >> input[2];
		input[0] = t;
		sort(input);
		vector<double>outputs = testNet.Update(input);
		if (!outputs.empty())
			ofs << tags[outputs[0] * outputs[0] * tags.size()] << endl;
		else
			ofs << "null" << endl;
	}
}