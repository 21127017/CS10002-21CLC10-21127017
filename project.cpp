#include <bits/stdc++.h>

using namespace std;

struct SLL_Node{
	int data;
	struct SLL_Node *next;
};

struct SLL_Node *head;

void Traversed(){
	struct SLL_Node *current = head;
	cout << "Singly Linked List: [";
	while (current != NULL){
		cout << current -> data;
		current = current -> next;
		if (current != NULL) cout << " -> ";
	}
	cout << "]" << endl;
	return;
}

struct SLL_Node *Create_Node(int &data){
	struct SLL_Node *auxilary = new SLL_Node;
	auxilary -> data = data;
	auxilary -> next = NULL;
	return auxilary;
}

void Insert_Node(int &data, int &pos, int &len){
	if (pos < 1 || (pos > len && pos != 1)){
		cout << "The position does not exits." << endl;
		return;
	}
	++len;
	struct SLL_Node *current = head;
	struct SLL_Node *newnode = Create_Node(data);
	if (pos == 1){
		newnode -> next = current;
		head = newnode;
		return;
	}
	int k = 1;
	while (k != pos - 1){
		++k;
		current = current -> next;
	}
	newnode -> next = current -> next;
	current -> next = newnode;
	return;
}

void Delete_Node(int &pos, int &len){
	if (pos < 1 || pos > len){
		cout << "The position does not exits." << endl;
		return;
	}
	--len;
	struct SLL_Node *current = head;
	if (pos == 1){
		head = head -> next;
		free(current);
		return;
	}
	int k = 1;
	while (k != pos - 1){
		++k;
		current = current -> next;
	}
	struct SLL_Node *auxilary = current -> next;
	current -> next = current -> next -> next;
	free(auxilary);
	return;
}

void Delete_Linked_List(){
	struct SLL_Node *current = head;
	struct SLL_Node *auxilary;
	while (current != NULL){
		auxilary = current;
		current = current -> next;
		free(auxilary);
	}
	return;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("CF.INP", "r", stdin);
    	freopen("CF.OUT", "w", stdout);
	#endif // ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, len = 0;
	head = NULL;

	cin >> t;
	while (t--){
		int condition, data, pos;
		cin >> condition;
		// Add node to SLL
		if (condition == 1){ 
			cin >> data >> pos;
			Insert_Node(data, pos, len);
			Traversed();
		} else 
		//Delete node from SLL
		if (condition == 2){
			cin >> pos;
			Delete_Node(pos, len);
			Traversed();
		}
	}

	return 0;
}