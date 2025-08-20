// Lab 3 - SECJ2013 - 24251 (Lab3.cpp)
// Group Members:
// 1. Chua Jia Lin A23CS0069
// 2. Cheryl Cheong Kah Voon A23CS0060

#include <iostream>
#include <string>

using namespace std;

// Class section
class Node {
  public:
    int data;
    Node *next, *prev;

    Node(int n) {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

// List class (linked list)
class List {
    private:
       Node *head;
       Node *last;

    public:
        List() { head = NULL; last = NULL; }

        ~List() {
            Node *n = head;

            while (n != NULL) {
                Node *temp = n;
                n = n->next;
                delete(temp);
            }
        }

        bool isEmpty() {  return head == NULL; }

        // please complete the insertNode function
        void insertNode(int val) {
            Node *newNode = new Node(val);
            if(isEmpty()){
            	head=last=newNode;
			}
			else if(val<=head->data){
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
			else if(val>=last->data){
				newNode->prev=last;
				last->next=newNode;
				last=newNode;
			}
			else{
				Node *curr=head;
				while(curr->next && curr->next->data<val){
					curr=curr->next;
				}
				newNode->next=curr->next;
				newNode->prev=curr;
				if(curr->next){
					curr->next->prev=newNode;
				}
				curr->next=newNode;
			}
        }

        int findNode(int n) {
           Node *currNode = head;
           int post = 1;
           while (currNode != NULL) {
               if (n == currNode->data) return post;
               currNode = currNode->next;
               post++;
           }

           return 0;
        }

        // please complete the deleteNode function
        int deleteNode(int n) {
        	Node *curr=head;
        	int currIndex=findNode(n);
            if(currIndex==0){
            	return 0;
			}
			for(int i=1;i<currIndex;i++){
				curr=curr->next;
			}
			if(curr==head){
				head=curr->next;
				if(head){
					head->prev=NULL;
				}
			}
			else if(curr==last){
				last=curr->prev;
				if(last){
					last->next=NULL;
				}
			}
			else{
				curr->prev->next=curr->next;
				if(curr->next){
					curr->next->prev=curr->prev;
				}
			}
			cout<<endl;
			cout<<"Delete node "<<n<<" at position = "<<currIndex<<endl<<endl;
			delete curr;
			return currIndex;
        }

        void displayList() {
            Node *n = head;
            cout << "displayList:\n";
            
            while (n != NULL) {
                cout << n->data << " ";
                n = n->next;
            }
            
            cout << "\n";
        }
        
        void displayListReverse() {
            Node *n = last;
            cout << "displayListReverse:\n";
            
            while (n != NULL) {
                cout << n->data << " ";
                n = n->prev;
            }
            
            cout << "\n";
        }
};


// Main function section
int main() {
   List linkedList;

   // do not change this insert values sequence
   linkedList.insertNode(0);
   linkedList.insertNode(9);
   linkedList.insertNode(1);
   linkedList.insertNode(6);
   linkedList.insertNode(5);

   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(5);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(0);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(9);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   return 0;
}
