/*
* Name: Andres Valencia Cardenas
* Course: CPTS 223, Fall 2025
* Assignment: PA3
* Description: Header file for map template, includes class declaration and function definitions. 
* Date: 10/18/2025
*/ 
#pragma once
#include <utility> // for std::pair
#include <algorithm> // for std::max
using namespace std; 

//node definition
template<class T, class S>
struct Node {
	int height; 
	T key; 
	S value; 
	Node* left;
	Node* right;

	Node(const T& K,const S& V) : key(K), value(V), left(nullptr), right(nullptr),
		height(0) {}
};

//MyMap class definition
template <class T, class S>
class Map
{
public:

	//constructors
	Map() : head_(nullptr), count_(0) {}

	~Map()
	{
		Clear(head_);
	}

	//Iterator class definition for find() , begin() and end() 
	class Iterator 
	{
	public:

		//class attributes
		Node<T, S>* node_;
		const Map<T, S>* map_;

		//constructor
		Iterator(Node<T,S>* node = nullptr, const Map<T,S>* map = nullptr) : 
			node_(node), map_(map) {}
		
		//overloaded operators

        pair<const T&, S&> operator*() const {
            return {node_->key, node_->value};
        }

		bool operator==(const Iterator& other) const
		{
			return node_== other.node_; 
		}

		bool operator!=(const Iterator& other) const
		{
			return node_ != other.node_; 
		}

		Iterator& operator++()
		{
			node_ = map_->NextNode(node_); 
			return *this; 
		}

		// Class methods

		/*
		* @param: none
		* returns: node pointer 
		* returns the current node 
		*/
		Node<T, S>* GetNode() const
		{
			return node_; 
		}
	};
	// Class methods for MyMap class

	/*
	* @param: a pair of type T and S
	* returns: none
	* helper function for the Insert method, inserts a new pair into the map
	* Increments the count 
	*/
	void Insert(const T& key, const S& value)
	{
		head_ = Insert(key, value, head_);
		count_++;
	}
	
	/*
	* @param: Key of type T
	* @param: Value of type S
	* returns: none
	* Helper function for the Emplace method, 
	* which inserts a new pair with the key and value passed in as a parameters
	*/
	void Emplace(const T& key, const S& value)
	{
		head_ = Emplace(key, value, head_);
		count_++;
	}

	/*
	* @param: A key of type T
	* returns: none
	* helper function for the Erase method, which removes an element from the map. 
	*/
	void Erase(const T& key)
	{
		head_ = Erase(key, head_);
		count_--;
	}

	/*
	* @param: none
	* returns: integer value 
	* returns the number of elements in the map
	*/
	int Size()
	{
		return count_;
	}

	/*
	* @param: none
	* returns: boolean value
	* Returns true if the map is empty, false otherwise
	*/
	bool Empty()
	{
		return head_ == nullptr;
	}

	/*
	* @param: none
	* returns: Iterator object
	* returns an iterator to the beginning of the map 
	*/
	Iterator begin() const
	{
		return Iterator(MinNode(head_), this);
	}

	/*
	* @param: none
	* returns: Iterator object
	* returns a iterator object that represents the position after the end of the map. 
	*/
	Iterator end() const
	{
		return Iterator(nullptr, this);
	}

	/*
	* @param: A key of type T
	* returns: Iterator object
	* finds an element in the map based on the key,
	* will return end() if the key is not found. 
	*/
	Iterator Find(const T& key) const
	{
		Node<T, S>* current = head_; 
		while (current != nullptr)
		{
			if (key == current->key)
			{
				return Iterator(current, this);
			}
			else if (key < current->key)
			{
				current = current->left; 
			}
			else
			{
				current = current->right; 
			}
		}
		return end(); 
	}

private:

	//Private class methods

	/*
	* @param: A node pointer
	* returns: An integer value
	* Returns the height of the node passed as a parameter
	*/
	int Height(Node<T, S>* node) const
	{
		if (node == nullptr)
		{
			return -1;
		} 
		return node->height; 
	}

	/*
	* @param: a node pointer 
	* returns: an integer value
	* calculates and returns the balance factor of a node
	* balance factor is the height of the right subtree minus the height of the left subtree
	*/
	int BalanceFactor(Node<T, S>* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}
		return Height(node->right) - Height(node->left); 
	}

	/*
	* @param: a node pointer
	* returns a node pointer
	* finds the minimum node in a tree or subtree
	*/
	Node<T,S>* MinNode(Node<T, S>* node) const
	{
		while (node && node->left)
		{
			node = node->left; 
		}
		return node; 
	}

	/*
	* @param: a node pointer
	* returns: a node pointer
	* retuns the nodes successor 
	*/
	Node<T, S>* NextNode (Node<T,S>*node) const 
	{
		if (node->right != nullptr)
		{
			return MinNode(node->right); 
		}

		Node<T, S>* successor = nullptr; 
		Node<T, S>* ancestor = head_; 
		while (ancestor != node)
		{
			if (node->key < ancestor->key)
			{
				successor = ancestor; 
				ancestor = ancestor->left; 
			}
			else
			{
				ancestor = ancestor->right; 
			}
		}
		return successor; 
	}


	/*
	* @param: a node pointer
	* @returns: a node pointer
	* Performs a right rotation on the given node. 
	*/
	Node<T,S>* RotateRight(Node<T,S>* node)
	{
		Node<T,S>* node_x = node->left; 
		Node<T,S>* node_y = node_x->right; 
		node_x->right = node; 
		node->left = node_y; 
		node->height = max(Height(node->left), Height(node->right)) + 1; 
		node_x->height = max(Height(node_x->left), Height(node_x->right)) + 1; 
		return node_x; 
	}

	/*
	* @param: a node pointer 
	* returns: a node pointer 
	* Performs a left rotation on the given node.
	*/
	Node<T,S>* RotateLeft(Node<T,S>* node)
	{
		Node<T,S>* node_x = node->right; 
		Node<T,S>* node_y = node_x->left; 
		node_x->left = node; 
		node->right = node_y; 
		node->height = max(Height(node->left), Height(node->right)) + 1; 
		node_x->height = max(Height(node_x->left), Height(node_x->right)) + 1; 
		return node_x; 
	}

	/*
	* @param: a pair of type T and S
	* A node pointer 
	* inserts an element into the map and performs the necessary rotations
	* Adjusts the height of the node
	*/
	Node<T,S>* Insert(const T& key, const S& value, Node<T, S>* node)
	{
		if (node == nullptr)
		{
			return new Node<T,S>(key, value);  
		}

		if (key < node->key)
		{
			node->left = Insert(key,value ,node->left); 
		}
		else if (key > node->key)
		{
			node->right = Insert(key, value, node->right); 
		}
		else
		{
			node->value = value; 
			return node;
		}

		node->height = std::max(Height(node->left), Height(node->right)) + 1; 

		int balance_factor = BalanceFactor(node);

		//LL case
		if (balance_factor < -1 && key < node->left->key)
		{
			return RotateRight(node); 
		}

		//RR case
		if (balance_factor > 1 && key > node->right->key)
		{
			return RotateLeft(node); 
		}

		//LR case 
		if (balance_factor < -1 && key > node->left->key)
		{
			node->left = RotateLeft(node->left); 
			return RotateRight(node); 
		}

		//RL case 
		if (balance_factor > 1 && key < node->right->key)
		{
			node->right = RotateRight(node->right); 
			return RotateLeft(node); 
		}

		return node; 
	}


	/*
	* @param: A key of type T
	* @param: A value of type S
	* @param: A node pointer 
	* Inserts a new pair using key and value into the map 
	* Performs any necessary rotations
	* Adjusts the height of the node
	*/
	Node<T, S>* Emplace(const T& key, const S& value, Node<T, S>* node)
	{
		if(node == nullptr)
		{ 
			return new Node<T, S>(key, value);
		}

		if (key < node->key)
		{
			node->left = Emplace(key, value, node->left);
		}
		else if(key > node->key)
		{
			node->right = Emplace(key, value, node->right);
		}
		else
		{
			node->value = value; 
			return node; 
		}

		node->height = max(Height(node->left), Height(node->right)) + 1;

		int balance_factor = BalanceFactor(node); 

		//LL case 
		if (balance_factor < -1 && key < node->left->key)
		{
			return RotateRight(node);
		}

		//RR case 
		if (balance_factor > 1 && key > node->right->key)
		{
			return RotateLeft(node);
		}

		//LR case 
		if (balance_factor < -1 && key > node->left->key)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		//RL case 
		if (balance_factor > 1 && key < node->right->key)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}

		return node; 
	}

	/*
	* @param: A key of type T 
	* @param a node pointer
	* Deletes the element with the key passed in as a parameter from the map.
	* Performs any necessary rotations
	* Adjusts the height of the node
	*/
	Node<T,S>* Erase(const T& key, Node<T, S>* node)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (key < node->key)
		{
			node->left = Erase(key, node->left);
		}
		else if (key > node->key)
		{
			node->right = Erase(key, node->right);
		}
		else
		{
			if ((node->left == nullptr) || (node->right == nullptr))
			{
				Node<T, S>* temp = node->left ? node->left : node->right;
				if (temp == nullptr)
				{
					temp = node;
					node = nullptr;
				}
				else
				{
					*node = *temp;
				}
				delete temp;
			}
			else
			{
				Node<T, S>* temp = node->right;
				while (temp->left != nullptr)
				{
					temp = temp->left;
				}
				node->key = temp->key;
				node->value = temp->value; 
				node->right = Erase(temp->key, node->right);
			}
		}

		if (node == nullptr)
		{
			return node;
		}

		node->height = max(Height(node->left), Height(node->right)) + 1;

		int balance_factor = BalanceFactor(node);
		//LL case
		if (balance_factor < -1 && BalanceFactor(node->left) <= 0)
		{
			return RotateRight(node);
		}
		//RR case
		if (balance_factor > 1 && BalanceFactor(node->right) >= 0)
		{
			return RotateLeft(node);
		}
		//LR case
		if (balance_factor < -1 && BalanceFactor(node->left) > 0)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}
		//RL case
		if (balance_factor > 1 && BalanceFactor(node->right) < 0)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}
		return node;
	}
	
	/*
	* @param: a node pointer
	* returns: none
	* clears the entire map and deallocates memory
	*/
	void Clear(Node<T, S>* node)
	{
		if (node == nullptr) return; 
		Clear(node->left); 
		Clear(node->right); 
		delete node; 
	}
	
	//Private class members 
	Node<T, S>* head_; 
	int count_; 
};

