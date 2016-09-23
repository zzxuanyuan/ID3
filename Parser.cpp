#include "Item.h"
#include "Instance.h"

using namespace std;

class Parser;

static parseMonkI(string file_name) {
	ifstream infile(file_name);
	vector<Item> item_vec;
	m_instance_vec = new vector<Instance>();
	Item it0(0,3,true);
	Item it1(1,0,false);
	Item it2(2,0,false);
	Item it3(3,0,false);
	Item it4(4,0,false);
	Item it5(5,0,false);
	Item it6(6,0,false);
	Item it7(7,1,false);

	while(infile >> it0 >> it1 >> it2 >> it3 >> it4 >> it5 >> it6 >> it7) {
		m_instance_vec->push_back(new vector<Item>(it0, it1, it2, it3, it4, it5, it6, it7));
	}
}

static parseCongressVote(string file_name) {
}

static parseHumanActivity(string file_name) {
}

Parser::Parser(string file_type, string file_name) {
	if (file_type == "MonkI") parseMonkI(file_name);
	else if (file_type == "CongressVote") parseCongressVote(file_name);
	else if (file_type == "HumanActivity") parseHumanActivity(file_name);
	else;
}

string Parser::getFileType() {
	return m_file_type;
}

void Parser::setFileType(string file_type) {
	m_file_type = file_type;
}

vector<Instance> *Parser::getInstanceVec() {
	return m_instance_vec;
}

void Parser::setInstanceVec(vector<Instance> *instance_vec) {
	m_instance_vec = instance_vec;
}

