#ifndef PARSER_H
#define PARSER_H

#include<vector>
#include<string>
#include "Item.h"
#include "Instance.h"

using namespace std;

static vector<Instance> *parseMonkI(string file_name) {
	ifstream infile(file_name);
	vector<Item> item_vec;
	vector<Instance> *instance_vec_ptr = new vector<Instance>();
	Item it0(0,2,true);
	Item it1(1,0,false);
	Item it2(2,0,false);
	Item it3(3,0,false);
	Item it4(4,0,false);
	Item it5(5,0,false);
	Item it6(6,0,false);
	Item it7(7,1,false);

//	int inttest;
//	infile >> inttest;
//	cout << "inttest = " << inttest << endl;
	while(infile >> it0 >> it1 >> it2 >> it3 >> it4 >> it5 >> it6 >> it7) {
		cout << it0.getBoolVal() << it1.getIntVal() << it2.getIntVal() << it3.getIntVal() << it4.getIntVal() << it5.getIntVal() << it6.getIntVal() << it7.getStringVal() << endl;
		item_vec.push_back(it0); item_vec.push_back(it1); item_vec.push_back(it2); item_vec.push_back(it3); 
		item_vec.push_back(it4); item_vec.push_back(it5); item_vec.push_back(it6); item_vec.push_back(it7); 
		(*instance_vec_ptr).push_back(item_vec);
		item_vec.clear();
	}
	vector<Instance> test = *instance_vec_ptr;
	cout << "test size = " << test.size() << endl;
	return instance_vec_ptr;
}

static vector<Instance> *parseCongressVote(string file_name) {
	ifstream infile(file_name);
	vector<Item> item_vec;
	vector<Instance> *instance_vec_ptr = new vector<Instance>();
	return instance_vec_ptr;
}

static vector<Instance> *parseHumanActivity(string file_name) {
	ifstream infile(file_name);
	vector<Item> item_vec;
	vector<Instance> *instance_vec_ptr = new vector<Instance>();
	return instance_vec_ptr;
}

class Parser {
	private:
		string m_file_type;
		vector<Instance> *m_instance_vec_ptr;
	public:
		Parser(){}
		void startParsing(string file_type, string file_name) {
			if (file_type == "MonkI") {
				m_instance_vec_ptr = parseMonkI(file_name);
			} else if (file_type == "CongressVote") {
				m_instance_vec_ptr = parseCongressVote(file_name);
			} else if (file_type == "HumanActivity") {
				m_instance_vec_ptr = parseHumanActivity(file_name);
			} else {}
		}
		string getFileType() { return m_file_type; }
		void setFileType(string file_type) { m_file_type = file_type; }
		vector<Instance> *getInstanceVec() { return m_instance_vec_ptr; }
		void setInstanceVec(vector<Instance> *instance_vec_ptr) { m_instance_vec_ptr = instance_vec_ptr; }

};

#endif
