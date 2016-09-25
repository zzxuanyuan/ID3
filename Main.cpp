#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Item.h"
#include "Instance.h"
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[]) {
	switch (argc) {
		case 1:
			cout << "Please specify an file type: MonkI, CongressVote, HumanAcitivity." << endl;
			cout << "Syntax: ./main fileType dataFile" << endl;
			return 1;
		case 2:
			cout << "Please specify a input data file." << endl;
			cout << "Syntax: ./main fileType dataFile" << endl;
			return 1;
		case 3:
			break;
		default:
			cout << "Too many arguments." << endl;
			cout << "Syntax: ./main fileType dataFile" << endl;
			return 1;
	}

	vector<Instance> data;
	string arg1 = string(argv[1]);
	string arg2 = string(argv[2]);
	Parser parser;
	cout << "start parsing" << endl;
	parser.startParsing(arg1, arg2);
	vector<Instance> *instance_vec_ptr = parser.getInstanceVec();
	data = *instance_vec_ptr;
	vector<Item> it_vec = data[0].getItemVec();
	Item it = it_vec[0];
	cout << it.getType() << it.getDoubleVal() << endl;
//	it.setType(3);
//	cout << "start parsing" << endl;
//	cin >> it;
//	double out = it.getDoubleVal();
//	cout << out << endl;
	return 0;
}
