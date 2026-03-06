#include <iostream>
#include <memory>
#include <optional>

class BST
{
	private:
		struct Node
		{
			int data;
			std::unique_ptr<Node> left;
			std::unique_ptr<Node> right;

			Node(int value) : data(value) {}
		};

		std::unique_ptr<Node> root;

	public:
		// Insert
		void insert(int value)
		{
			insertImpl(root, value);
		}

		// Search
		bool search(int value) const
		{
			return searchImpl(root.get(), value);
		}

		// Delete
		void remove(int value)
		{
			removeImpl(root, value); // api style
		}

		// Inorder Traversal
		void inorder() const
		{
			inorderImpl(root.get());
			std::cout << "\n";
		}

		// Find Min
		std::optional<int> findMin() const
		{
			Node* current = root.get();
			if (!current) return std::nullopt;

			while (current->left)
				current = current->left.get();

			return current->data;
		}

		// Find Max
		std::optional<int> findMax() const
		{
			Node* current = root.get();
			if (!current) return std::nullopt;

			while (current->right)
				current = current->right.get();

			return current->data;
		}

	private:
		// Insert Implementation
		void insertImpl(std::unique_ptr<Node>& node, int value)
		{
			if (!node)
			{
				node = std::make_unique<Node>(value);
				return;
			}

			if (value < node->data)
				insertImpl(node->left, value);
			else if (value > node->data)
				insertImpl(node->right, value);
		}

		// Search Implementation
		bool searchImpl(const Node* node, int value) const
		{
			if (!node) return false;

			if (value == node->data)
				return true;
			else if (value < node->data)
				return searchImpl(node->left.get(), value);
			else
				return searchImpl(node->right.get(), value);
		}

		// Remove Implementation
		/*  50
		    /  \
		    30   70
		    /  \
		    20  40  */
		void removeImpl(std::unique_ptr<Node>& node, int value) // 40(subtree node), 40
		{
			if (!node) // (!nullptr)
				return; // node =50

			if (value < node->data) // 20 < 50 , 20 < 30
				removeImpl(node->left, value); // 30 ,20 = node(30) , 20,20 = node(20)
			else if (value > node->data) // 
				removeImpl(node->right, value);

			else // after locating node then else will execute
			{
				// Case 1: No child -leaf node
				if (!node->left && !node->right)
				{
					node.reset();
				}
				// Case 2: One child
				else if (!node->left) // node->left=nullptr , one right child
				{
					node = std::move(node->right);
				}
				else if (!node->right) // node->right=nullptr , one left child
				{
					node = std::move(node->left);
				}

				// Case 3: Two children
				/*        50
					  /  \
					  30   70
					  /  \
					  20  40 

				 */
				else // node=30 is uqptr ,30 have 2 child
				{
					Node* minNode = node->right.get(); // minNode  is a raw pointer  minNode= node->right.get()extracting the raw ptr
									   // minnode =40 
					while (minNode->left) // minNode->left =nullptr
						minNode = minNode->left.get(); //

					node->data = minNode->data; // copy not move, 30 = 40 ,30 will be replaced with data 40
					/*    50
					      /  \
					      40   70
					      /  \
					      20  40 (original node-> right passing to fun )

					 */
					removeImpl(node->right, minNode->data); // removeImpl(node right sub tree(40),40)
				}
			}
		}

		void inorderImpl(const Node* node) const
		{
			if (!node) return;

			inorderImpl(node->left.get());
			std::cout << node->data << " ";
			inorderImpl(node->right.get());
		}
};

int main()
{
	BST tree;

	tree.insert(50);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.insert(40);
	tree.insert(60);
	tree.insert(80);

	std::cout << "Inorder: ";
	tree.inorder();

	std::cout << "Search 40: " << (tree.search(40) ? "Found\n" : "Not Found\n");

	tree.remove(30);
	std::cout << "After deleting 30: ";
	tree.inorder();

	if (auto min = tree.findMin())
		std::cout << "Min: " << *min << "\n";

	if (auto max = tree.findMax())
		std::cout << "Max: " << *max << "\n";

	return 0;
}

