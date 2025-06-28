#include"RedBlackTree.h"
template<class T>
class myRBT : public Tree<T> {
	Node<T>* root;
protected:
	void POSTORDER(Node<T>*p);
	void POSTORDER2(Node<T>*p);
	void PREORDER(Node<T>*p);
	void PREORDER2(Node<T>*p);
	void INORDER2(Node<T>* node);
	void INORDER(Node<T>* node);
	Node<T>* SEARCH(Node<T>* node, int data);
	
	void updateNodeAtPath(Node<T>*& root, string path, Node<T>* newNode);
	Node<T>* getNodeAtPath(Node<T>* root, string path);
	Node<T>* rightRotate(Node<T>* right);
	Node<T>* leftRotate(Node<T>* left);
	void destroyTree(Node<T>* node);

public:
	myRBT();
	void RB_insert(T value);
	void RB_search(T data);
	void RB_inorderLNR();
	void RB_preorderNLR();
	void RB_postorderLRN();
	void RB_inorderRNL();
	void RB_preorderNRL();
	void RB_postorderRLN();
	
	void RB_displayParentOf(T value);
	void RB_loadFromFile();
	void RB_clearTree();
};
template<class T>
myRBT<T>::myRBT(){
	root = nullptr;
}

template<class T>
void myRBT  <T>::RB_insert(T value)
{
	Node<T>* newNode = new Node<T>(value);
	string insertPath = "";

	if (root == nullptr) {
		newNode->color = "BLACK";
		root = newNode;
		return;
	}

	Node<T>* current = root;
	Node<T>* parent = nullptr;

	while (current != nullptr) {
		parent = current;

		if (value < current->data) {
			insertPath = insertPath+ 'L';
			if (current->left == nullptr) {
				current->left = newNode;
				break;
			}
			current = current->left;
		}
		else {
			insertPath = insertPath + 'R';
			if (current->right == nullptr) {
				current->right = newNode;
				break;
			}
			current = current->right;
		}
	}

	int len = 0;


	while (insertPath[len] != '\0') len++;

	if (len < 1)
		return;

	string currentPath = "";
	for (int i = 0; i < len; i++) {
		currentPath = currentPath + insertPath[i];
	}

	while (len >= 2) {

		Node<T>* current = getNodeAtPath(root, currentPath);


		string parentPath;
		for (int i = 0; i < len - 1; i++)
			parentPath = parentPath + currentPath[i];

		parentPath[len - 1] = '\0';
		Node<T>* parent = getNodeAtPath(root, parentPath);


		if (parent->color == "BLACK")
			break;


		if (len - 1 == 0) {
			parent->color = "BLACK";
			break;
		}

		string grandPath;
		for (int i = 0; i < len - 2; i++)
			grandPath = grandPath + currentPath[i];


		grandPath[len - 2] = '\0';
		Node<T>* grand = getNodeAtPath(root, grandPath);


		char dir = currentPath[len - 2];
		Node<T>* uncle;

		if (dir == 'L') {
			uncle = grand->right;
		}
		else {
			uncle = grand->left;
		}



		if (uncle != nullptr && uncle->color == "RED") {
			parent->color = "BLACK";
			uncle->color = "BLACK";
			grand->color = "RED";

			len -= 2;
			currentPath[len] = '\0';
			continue;
		}


		char currentDir = currentPath[len - 1];

		if (dir == 'L') {
			if (currentDir == 'R') {
				Node<T>* newParent = leftRotate(parent);
				updateNodeAtPath(root, parentPath, newParent);
				parent = newParent;
			}
			parent->color = "BLACK";
			grand->color = "RED";
			Node<T>* newGrand = rightRotate(grand);
			updateNodeAtPath(root, grandPath, newGrand);
		}
		else {
			if (currentDir == 'L') {
				Node<T>* newParent = rightRotate(parent);
				updateNodeAtPath(root, parentPath, newParent);
				parent = newParent;
			}
			parent->color = "BLACK";
			grand->color = "RED";
			Node<T>* newGrand = leftRotate(grand);
			updateNodeAtPath(root, grandPath, newGrand);
		}
		break;
	}

	if (root)
		root->color = "BLACK";
	
}
template<class T>
Node<T>* myRBT<T>::leftRotate(Node<T>* left){
	Node<T>* y = left->right;
	left->right = y->left;
	y->left = left;
	return y;
}

template<class T>
Node<T>* myRBT<T>::rightRotate(Node<T>* right){
	Node<T>* y = right->left;
	right->left = y->right;
	y->right = right;
	return y;
}

template<class T>
Node<T>* myRBT<T>::getNodeAtPath(Node<T>* root, string path)
{
	Node<T>* current = root;
	for (int i = 0; path[i] != '\0'; i++) {
		char c = path[i];
		if (current == nullptr)
			return nullptr;
		if (c == 'L') {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return current;
}

template<class T>
void  myRBT<T>::updateNodeAtPath(Node<T>*& root, string path, Node<T>* newNode)
{
	if (path.empty()) {
		root = newNode;
		return;
	}

	Node<T>* current = root;
	for (int i = 0; i < path.length() - 1; i++) {
		if (path[i] == 'L') {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (path.back() == 'L') {
		current->left = newNode;
	}
	else {
		current->right = newNode;
	}
}
template<class T>
void  myRBT<T>::PREORDER(Node<T>*p)
{
	if (p != nullptr)
	{
		cout << p->data << " " << p->color << "  ";
		PREORDER(p->right);
		PREORDER(p->left);

	}
}
template<class T>
void  myRBT<T>::PREORDER2(Node<T>*p)
{
	if (p != nullptr)
	{
		cout << p->data << " " << p->color << "  ";
		PREORDER2(p->left);   
		PREORDER2(p->right);  
	}
}
template<class T>
void  myRBT<T>::INORDER(Node<T>* node)
{
	if (node != nullptr) {
		INORDER(node->left);
		cout << node->data << " " << node->color << "  ";
		INORDER(node->right);
	}
}

template<class T>
void myRBT<T>::INORDER2(Node<T>* node) {
	if (node != nullptr) {
		INORDER2(node->right);
		cout << node->data << " " << node->color << "  ";
		INORDER2(node->left);
	}
}

template<class T>
void  myRBT<T>::POSTORDER2(Node<T>*p)
{
	if (p != nullptr)
	{
		POSTORDER2(p->right);
		POSTORDER2(p->left);
		cout << p->data << " " << p->color << "  ";
	}
}
template<class T>
void  myRBT<T>::POSTORDER(Node<T>*p)
{
	if (p != nullptr)
	{

		POSTORDER(p->left);
		POSTORDER(p->right);
		cout << p->data << " " << p->color << "  ";
	}
}

template<class T>
Node<T>* myRBT<T>::SEARCH(Node<T>* p, int data)
{
	if (p == nullptr || data == p->data) {
		return p;
	}
	if (data < p->data) {
		return SEARCH(p->left, data);
	}
	return SEARCH(p->right, data);
}

template<class T>
void  myRBT<T>::RB_search(T data) {
	Node<T>* result = SEARCH(root, data);
	if (result != nullptr) {
		cout << "Value Found: " << result->data << " Color: " << result->color<< endl;
	}
	else {
		cout << "Value not found." << endl;
	}
}



template<class T>
void  myRBT<T>::RB_inorderRNL()
{
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	INORDER2(root);
	cout << endl;
}

template<class T>
void  myRBT<T>::RB_inorderLNR()
{
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}
	INORDER(root);
	cout << endl;
}

template<class T>
void  myRBT<T>::RB_preorderNLR()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		PREORDER(root);
}

template<class T>
void  myRBT<T>::RB_preorderNRL()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		PREORDER2(root);
}

template<class T>
void  myRBT<T>::RB_postorderLRN()
{
	
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		POSTORDER(root);
}

template<class T>
void  myRBT<T>::RB_postorderRLN()
{
	if (root == nullptr)
		cout << "Tree is empty" << endl;

	else
		POSTORDER2(root);
}

template<class T>
void  myRBT<T>::RB_displayParentOf(T value) {
	if (root == nullptr) {
		cout << " Tree is empty." << endl;
		return;
	}
	if (root->data == value){
		cout << "value is root value" << endl;
	}
	Node<T>* current = root;
	Node<T>* parent = nullptr;

	while (current != nullptr) {
		if (current->data == value) {
			if (parent)
				cout << "Parent of " << value << " is: " << parent->data << " (" << parent->color << ")" << endl;
			else
				cout << "No parent exists (value is root)." << endl;
			return;
		}
		parent = current;
		if (value < current->data)
			current = current->left;
		else
			current = current->right;
	}

	cout << "Value not found in tree." << endl;
}
template<class T>
void  myRBT<T>::RB_loadFromFile() {
	ifstream file("input.txt");
	if (!file.is_open()) {
		cout << "File not opened" << endl;

	}
	else{
		int val;
		while (file >> val) {
			RB_insert(val);
		}
	}
	file.close();
	cout << "Values inserted from file successfully" << endl;
}
template<class T>
void  myRBT<T>::destroyTree(Node<T>* node) {
	if (!node)
		return;
	destroyTree(node->left);
	destroyTree(node->right);
	delete node;
	node = nullptr;
}

template<class T>
void  myRBT<T>::RB_clearTree() {
	destroyTree(root);
	root = nullptr;
	cout << "Tree destroyed successfully." << endl;
}