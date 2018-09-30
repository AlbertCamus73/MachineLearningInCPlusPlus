/*******************************************************************
*����־�� ����ѧϰ��C++����
*
* htfeng
* 2018.09.30
*
* �����£�����ģ��
* ����һ������������
*******************************************************************/
#ifndef ML_DECISION_H//��������û�б�����
#define ML_DECISION_H//�����

#include "DecisionTreeStruct.h"
#include <string> 
#define MAXLEN 6 //����ÿ�е����ݸ���  

class DecisionTree {
public:
	__declspec(dllexport) DecisionTree(vector<vector<string>> state, int tree_size);
	__declspec(dllexport) void ComputeMapFrom2DVector();
	__declspec(dllexport) double ComputeEntropy(vector <vector <string> > remain_state, string attribute, string value, bool ifparent);
	__declspec(dllexport) double ComputeGain(vector <vector <string> > remain_state, string attribute);
	__declspec(dllexport) int FindAttriNumByName(string attri);
	__declspec(dllexport) string MostCommonLabel(vector <vector <string> > remain_state);
	__declspec(dllexport) bool AllTheSameLabel(vector <vector <string> > remain_state, string label);
	__declspec(dllexport) Node * BulidDecisionTreeDFS(Node * p, vector <vector <string> > remain_state, vector <string> remain_attribute);
	__declspec(dllexport) void Input();
	__declspec(dllexport) void PrintTree(Node *p, int depth);
	__declspec(dllexport) void FreeTree(Node *p);

private:
	vector <vector <string> > state;//ʵ����  
	vector <string> item{ MAXLEN };//��Ӧһ��ʵ����  
	vector <string> attribute_row;//�������м�����������  
	string end = "end";//�������  
	string yes = "yes";
	string no = "no";
	string blank = "";
	map<string, vector < string > > map_attribute_values;//�洢���Զ�Ӧ�����е�ֵ  
	int tree_size = 0;
};
#endif