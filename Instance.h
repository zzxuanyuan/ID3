#include <vector>
#include "Item.h"

using namespace std;

class Instance {
private:
	vector<Item> m_item_vec;
	int m_item_num;
	int m_id;
	unordered_map<int, string> m_id_map = 0;
	int m_label;
public:
	Instance(int item_num, int item_val) {
		m_item_num = item_num;
		m_item_vec = vector<Item>(item_num, Item(0));
	}

	Instance(int item_num, string item_val) {
		m_item_num = item_num;
		m_item_vec = vector<Item>(item_num, Item(""));
	}

	Instance(int item_num, bool item_val) {
		m_item_num = item_num;
		m_item_vec = vector<Item>(item_num, Item(0));
	}

	Instance(int item_num, double item_val) {
		m_item_num = item_num;
		m_item_vec = vector<Item>(item_num, Item(0.0));
	}

	Instance(vector<item> &item_vec) {
		m_item_num = item_vec.size();
		m_item_vec = item_vec;
	}

	~Instance() {}

	vector<Item> getItemVec() { return m_item_vec; }
	void setItemVec(vector<Item> &item_vec) { m_item_vec = item_vec; }
	int getItemNum() { return m_item_num; }
	void setItemNum(int item_num) { m_item_num = item_num; }
	string getIdString(int id) { return m_id_map[id]; }
	void setIdString(int id, string id_string) { m_id_map[id] = id_string; }
	int getLabel() { return m_label; }
	void setLabel(int label) { m_label = label; }
}
