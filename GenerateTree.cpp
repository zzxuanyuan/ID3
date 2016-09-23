#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

double NodeEntropy(vector< vector<Instance> > &data, vector <int> &label) {
	vector<double> probs(label.size(), 0.0);
	for (int i = 0; i < data.size(); ++i ) {
		for (int j = 0; j < label.size(); ++j) {
			if (data.getLabel() == label[j])
				probs[j]++;
		}
	}
	for (int j = 0; j < label.size(); ++j) {
		probs[j] = probs[j]/(double)data.size();
	}
	double entropy = 0.0;
	for (int i = 0; i < probs.size(); ++i) {
		entropy += probs[i]*log2(probs[i]);
	}
	return entropy;
}

void CreateLeaf(vector< vector<Instance> > &data, TreeNode *root) {
	vector<int> classN(label.size(), 0);
	for (int i = 0; i < data.size(); ++i ) {
		for (int j = 0; j < label.size(); ++j) {
			if (data.getLabel() == label[j])
				classN[j]++;
		}
	}
	root->setClass(classN);
}

vector< vector< vector<Instance> > * > DivideData(vector< vector<Instance> > &data, Attribute &splitAttr) {
	int classN = splitAttr.getClassN();
	vector< vector< vector<Instance> > * > subsets(classN, NULL);
	for( int i = 0; i < classN; ++i) {
		subsets[i] = new vector< vector<Instance> >();
	}
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < classN; ++j) {
			if (data.getLabel() == j)
				subsets[j].push_back(data[i]);
		}
	}
	return subsets;
}

TreeNode* GenerateTree(vector< vector<Instance> > &data, TreeNode *root) {
	if (NodeEntropy(data) < THRESHOLD) {
		CreateLeaf(data, root);
		return 0;
	}

	Attribute splitAttr = SplitAttribute(data);
	vector< vector< vector<Instance> > * > subsets;
	subsets = DivideData(data, splitAttr);

	for (int i = 0; i < subset.size(); ++i) {
		GenerateTree(*subsets[i], root->child[i]);
	}
	return 0;
}
