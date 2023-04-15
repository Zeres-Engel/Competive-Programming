#include <bits/stdc++.h>
using namespace std;

//I love this game
//game this love I

struct Node{
	string data;
	Node *next;
};

typedef struct Node* node;

bool empty(node top){
	return top == NULL;
}

int getSize(node top){
	int ans = 0;
	while(top != NULL){
		++ans;
		top = top->next;
	}
	return ans;
}

node makeNode(string x){
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

void push(node &top, string x){
	node tmp = makeNode(x);
	if(top == NULL){
		top = tmp;
	}
	else{
		tmp->next = top;
		top = tmp;
	}
}

void pop(node &top){
	if(top == NULL) return;
	top = top->next;
}

string getTop(node top){
	return top->data;
}

int main(){
	node top = NULL;
	string s;
	getline(cin, s);
	stringstream ss(s);
	string word;
	while(ss >> word){
		push(top, word);
	}
	while(!empty(top)){
		cout << getTop(top) << " ";
		pop(top);
	}
	return 0;
}

