



//linked list impelmentation, copy and paste from https://www.youtube.com/watch?v=H5lkmKkfjD0

#ifndef link_list_h
#define link_list_h

class List{
	private:
		typedef struct node{
			int data;
			node* next;
		}* nodePtr;
	
		typedef vector<int> vi
	
		nodePtr head; // alternatively, nodePtr head;
		nodePtr current;
		nodePtr temp;
	public:
		List();
		void addNode(int newData);
		void deleteNode(int delData);
		void printList;
};
