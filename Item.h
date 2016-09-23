#include<vector>

using namespace std;

class Item {
private:
	int m_type;
	union m_val {
		int n;
		string s;
		bool b;
		double f;
	}
	bool m_is_label;
	int m_label;
	int m_attr;
public:
	Item(int attr, int val, bool is_label = false, int label = 0) {
		m_attr = attr;
		m_type = 0; // Numberic
		m_val = val;
		m_is_label = is_label;
		m_label = label;
	}

	Item(int attr, string val, bool is_label = false, int label = 0) {
		m_attr = attr;
		m_type = 1; // String
		m_val = val;
		m_is_label = is_label;
		m_label = label;
	}

	Item(int attr, bool val, bool is_label = false, int label = 0) {
		m_attr = attr;
		m_type = 3; // String
		m_val = val;
		m_is_label = is_label;
		m_label = label;
	}

	Item(int attr, double val, bool is_label = false, int label = 0) {
		m_attr = attr;
		m_type = 4; // String
		m_val = val;
		m_is_label = is_label;
		m_label = label;
	}

	~Item() {}

	int getAttr() { return m_attr; }
	void setAttr(int attr) { m_attr = attr; }
	int getType() { return m_type; }
	void setType(int type) { m_type = type; }
	auto getVal() { return m_val; }
	void setVal(auto val) { m_val = val; }
	bool isLabel() { return m_is_label; }
	int getLabel() { return m_label; }
	void setLabel(int label) { m_label = label; }
}
