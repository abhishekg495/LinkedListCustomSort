#include <bits\stdc++.h>

using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int a) {
			data = a;
			next = nullptr;
		}
};
int main(){
	
	int n,k;
	cin >> n >> k;
	node* head = nullptr;
	node* curr = nullptr;
	while(n--){
		int temp;
		cin >> temp;
		node* tempnode = new node(temp);
		if(head==nullptr){
			head=tempnode;
			curr=tempnode;
		}
		else{
			curr->next = tempnode;
			curr = tempnode;
		}
	}

	node* bakra;
	if(head->data >= k) bakra = nullptr;
	else {
		bakra = head;
		while(bakra->next!=nullptr && bakra->next->data<k) bakra = bakra->next;
	}

	node* tnode = head;
	while(tnode->next!=nullptr){
		if(tnode->next->data < k){
			int a = tnode->next->data;
			node* delnode = tnode->next;
			tnode->next = delnode->next;
			delete delnode;
			node* tempnode = new node(a);
			if(bakra!=nullptr){
				tempnode->next = bakra->next;
				bakra->next = tempnode;
				bakra = tempnode;
			}
			else{
				tempnode->next = head;
				head = tempnode;
				bakra= head;
			}
		}
		else tnode = tnode->next;
	}

	tnode = head;
	while(tnode!=nullptr){
		cout << tnode->data << " ";
		tnode = tnode->next;
	}
	return 0;
}