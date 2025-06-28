#include"myRBT.h"

int main() {
	myRBT<double> tree;
	int choice;
	double value;
	bool ischeck = true;

	while (ischeck) {
		cout << "\n===== Red-Black Tree Menu =====" << endl;
		cout << "1. Insert a value into the tree" << endl;
		cout << "2. Search for a value in the tree" << endl;
		cout << "3. Pre-order traversal (NLR)" << endl;
		cout << "4. In-order traversal (LNR)" << endl;
		cout << "5. Post-order traversal (LRN)" << endl;
		cout << "6. Pre-order traversal 2 (NRL)" << endl;
		cout << "7. In-order traversal 2 (RNL)" << endl;
		cout << "8. Post-order traversal 2 (RLN)" << endl;
		cout << "9. Display parent of a node" << endl;
		cout << "10. Read values from file" << endl;
		cout << "11. Destroy the tree" << endl;
		cout << "12. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Enter value: ";
			cin >> value;
			tree.RB_insert(value);
		}
		else if (choice == 2) {
			cout << "Enter value to search: ";
			cin >> value;
			tree.RB_search(value);
		}
		else if (choice == 3) {
			tree.RB_preorderNLR();
			cout << endl;
		}
		else if (choice == 4) {
			tree.RB_inorderLNR();
			cout << endl;
		}
		else if (choice == 5) {
			tree.RB_postorderLRN();
			cout << endl;
		}
		else if (choice == 6) {
			tree.RB_preorderNRL();
			cout << endl;
		}
		else if (choice == 7) {
			tree.RB_inorderRNL();
			cout << endl;
		}
		else if (choice == 8) {
			tree.RB_postorderRLN();
			cout << endl;
		}
		else if (choice == 9) {
			cout << "Enter value to find parent: ";
			cin >> value;
			tree.RB_displayParentOf(value);
		}
		else if (choice == 10) {
			tree.RB_loadFromFile();
		}
		else if (choice == 11) {
			tree.RB_clearTree();
		}
		else if (choice == 12) {
			ischeck = false;
		}
		else {
			cout << "Invalid option. Please try again." << endl;
		}
	}

	return 0;
}
