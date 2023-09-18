
#include<iostream>
#include<iomanip>
using namespace std;

class Node {
	string name;
	int id;
	int quantity;
	double price;
	Node* next;

public:
	// Getter and setter methods for the Node class
	string getName() const;
	int getId() const;
	int getQuantity() const;
	double getPrice() const;
	Node* getNext() const;
	void setName(string);
	void setId(int);
	void setQuantity(int);
	void setPrice(double);
	void setNext(Node*);
};

// Setter methods for Node class
void Node::setNext(Node* next) {
	this->next = next;
}

void Node::setName(string name) {
	this->name = name;
}

void Node::setId(int id) {
	this->id = id;
}

void Node::setQuantity(int quantity) {
	this->quantity = quantity;
}

void Node::setPrice(double price) {
	this->price = price;
}

// Getter methods for Node class
Node* Node::getNext() const {
	return this->next;
}

string Node::getName() const {
	return this->name;
}

int Node::getId() const {
	return this->id;
}

int Node::getQuantity() const {
	return this->quantity;
}

double Node::getPrice() const {
	return this->price;
}

class Inventory {
	Node* head;

public:
	// Constructor for Inventory class
	Inventory();
	
	// Methods for Inventory class
	void addProduct(string name, int id, int quantity, double price);
	void removeProduct(int);
	void updateProduct(int, int, double);
	void displayInventory() const;
};

// Constructor for Inventory class
Inventory::Inventory() {
	head = NULL;
}

// Method to update a product in the inventory
void Inventory::updateProduct(int id, int quantity, double price) {
	Node* newNode = head;
	while (newNode != NULL) {
		if (newNode->getId() == id) {
			newNode->setQuantity(quantity);
			newNode->setPrice(price);
			cout << "Product updated in inventory" << endl;
			return;
		}
		newNode = newNode->getNext();
	}
}

// Method to add a product to the inventory
void Inventory::addProduct(string name, int id, int quantity, double price) {
	Node* newNode = new Node;
	newNode->setName(name);
	newNode->setId(id);
	newNode->setQuantity(quantity);
	newNode->setPrice(price);
	newNode->setNext(NULL);

	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* last = head;
		while (last->getNext() != NULL) {
			last = last->getNext();
		}
		last->setNext(newNode);
	}

	cout << "Product Add Successfully" << endl;
}

// Method to remove a product from the inventory
void Inventory::removeProduct(int id) {
	if (head == NULL) {
		cout << "Inventory is Empty!" << endl;
		return;
	}

	if (head->getId() == id) {
		Node* temp = head;
		head = head->getNext();
		delete temp;
		cout << "Product Removed from inventory" << endl;
		return;
	}

	Node* newNode = head;
	while (newNode->getNext() != NULL) {
		if (newNode->getNext()->getId() == id) {
			Node* temp = newNode->getNext();
			newNode->setNext(newNode->getNext()->getNext());
			delete temp;
			cout << "Product Removed from inventory" << endl;
			return;
		}
		newNode = newNode->getNext();
	}

	cout << "Product not found in inventory" << endl;
}

// Helper method to display the inventory header
void show() {
	cout << "Inventory: " << endl
		<< "---------------------------------------" << endl
		<< "|   Name    |   ID   |  Quantity  |  Price  |" << endl
		<< "---------------------------------------" << endl;
}

// Method to display the inventory
void Inventory::displayInventory() const {
	if (head == NULL) {
		cout << "Inventory is Empty!" << endl;
		return;
	}
	show();
	Node* newNode = head;
	while (newNode != NULL) {
		cout << "| " << setw(10) << left << newNode->getName() << " | ";
		cout << setw(6) << left << newNode->getId() << " | ";
		cout << setw(10) << left << newNode->getQuantity() << " | ";
		cout << "$" << setw(7) << left << newNode->getPrice() << " |" << endl;
		newNode = newNode->getNext();
	}
	cout << "---------------------------------------" << endl;
}

int main() {
	Inventory inv;
	int choice, id, quantity, products;
	string name;
	double price;

	do {
		cout << "Please Choose an action: " << endl
			<< "1. Add Product\n"
			<< "2. Remove Product\n"
			<< "3. Update Product\n"
			<< "4. Display Inventory\n"
			<< "0. Exit\n";
		cout << "Enter Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "How many Products do you want to add?";
			cin >> products;
			for (int i = 0; i < products; i++) {
				cout << "Enter Product Name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter productID: ";
				cin >> id;
				cout << "Enter Product Quantity: ";
				cin >> quantity;
				cout << "Enter Product Price: ";
				cin >> price;
				inv.addProduct(name, id, quantity, price);
			}
			break;
		case 2:
			cout << "Enter productID to remove: ";
			cin >> id;
			inv.removeProduct(id);
			break;
		case 3:
			cout << "Enter productID to update: ";
			cin >> id;
			cout << "Enter new quantity: ";
			cin >> quantity;
			cout << "Enter new Price: ";
			cin >> price;
			inv.updateProduct(id, quantity, price);
			break;
		case 4:
			inv.displayInventory();
			break;
		case 0:
			cout << "Exiting Program...";
			break;
		}
		cout << endl;
	} while (choice != 0);

	return 0;
}
