#include"Node.h"

	template <class T>
	class Tree {

	public:
		virtual void RB_insert(T value) = 0;
		virtual void RB_search(T data) = 0;
		virtual void RB_inorderLNR() = 0;
		virtual void RB_preorderNLR() = 0;
		virtual void RB_postorderLRN() = 0;
		virtual void RB_inorderRNL() = 0;
		virtual void RB_preorderNRL() = 0;
		virtual void RB_postorderRLN() = 0;

		virtual void RB_displayParentOf(T value) = 0;
		virtual void RB_loadFromFile() = 0;
		virtual void RB_clearTree() = 0;
	};


