#include "Item.h"
#include "Instance.h"

class Parser {
private:
	string m_file_type;
	vector<Instance> *m_instance_vec;
public:
	string getFileType() { return m_file_type; }
	void setFileType(string file_type) { m_file_type = file_type; }
	vector<Instance> *getInstanceVec() { return m_instance_vec; }
	void setInstanceVec(vector<Instance> *instance_vec);

