#ifndef ITEM_H
#define ITEM_H

#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Item {
	private:
		int m_type;
		int m_val_int;
		string m_val_string;
		bool m_val_bool;
		double m_val_double;
		bool m_is_label;
		int m_label;
		int m_attr;
	public:
		Item() {}
		Item(int attr, int type, bool is_label = false, int label = 0) {
			cout << "item int" << endl;
			m_attr = attr;
			m_type = type; // 0:Numberic, 1:String, 2:Boolean, 3:Double
			m_is_label = is_label;
			m_label = label;
		}

		~Item() {}

		int getAttr() { return m_attr; }
		void setAttr(int attr) { m_attr = attr; }
		int getType() { return m_type; }
		void setType(int type) { m_type = type; }
		int getIntVal() { return m_val_int; }
		void setIntVal(int val) { m_val_int = val; }
		string getStringVal() { return m_val_string; }
		void setStringVal(string val) { m_val_string = val; }
		int getBoolVal() { return m_val_bool; }
		void setBoolVal(bool val) { m_val_bool = val; }
		double getDoubleVal() { return m_val_double; }
		void setDoubleVal(double val) { m_val_double = val; }
		bool isLabel() { return m_is_label; }
		int getLabel() { return m_label; }
		void setLabel(int label) { m_label = label; }

};

istream& operator>>(istream& is, Item& it) {
	switch(it.getType()) {
		case 0:
			{
				//cout << "int type" << endl;
				int val_int;
				is >> val_int;
				it.setIntVal(val_int);
				break;
			}
		case 1:
			{
				//cout << "string type" << endl;
				string val_string;
				is >> val_string;
				it.setStringVal(val_string);
				break;
			}
		case 2:
			{
				//cout << "boolean type" << endl;
				bool val_bool;
				is >> val_bool;
				it.setBoolVal(val_bool);
				break;
			}
		case 3:
			{
				//cout << "double type" << endl;
				double val_double;
				is >> val_double;
				it.setDoubleVal(val_double);
				break;
			}
		default:
			{
				//cout << "Unknow Item Type: " << endl;
				break;
			}
	}

	return is;
}

#endif // ITEM_H
