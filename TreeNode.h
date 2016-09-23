#include<vector>

using namespace std;

class TreeNode {
private:
	int m_attr;
	int m_start_index;
	int m_end_index;
	vector<TreeNode *> m_children;
	bool m_leaf;
public:
	TreeNode();
	~TreeNode();
	int getAttr() { return m_attr; }
	void setAttr(int attr) { m_attr = attr; }
	int getStartIndex() { return m_start_index; }
	void setStartIndex(int start_index) { m_start_index = start_index; }
	int getEndIndex() { return m_end_index; }
	void setEndIndex(int end_index) { m_end_index = end_index; }
	vector<TreeNode *> getAllChildren() { return m_children; }
	TreeNode * getIndexedChild(int index) { return m_children[index]; }
	bool isLeaf() { return m_leaf; }
	void setLeaf(bool leaf) { m_leaf = leaf; }
}

class InterNode : class TreeNode {
private:
	vector<int> m_label_vec;
public:
	InterNode() { m_leaf = false; }
	InterNode(int attr) { m_attr = attr; }
	~InterNode();
}

class LeafNode : class TreeNode {
private:
	int m_label;
	vector<int> m_label_vec;
public:
	LeafNode() { m_leaf = true; }
	LeafNode(int label) { m_label = label; }
	~LeafNode();
}
