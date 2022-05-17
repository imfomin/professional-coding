#include <stdio.h>

struct int_unit {
	int value;
	int_unit* next;
};


int_unit* init(int n) {
	int_unit* root = new int_unit;
	
	root->value = n; 
	root->next = NULL;

	return root;
}

int_unit* append(int_unit* root, int _value) {
	int_unit* cur = root;

	while (cur->next) {
		cur = cur->next;
	}

	int_unit* new_unit = new int_unit;

	cur->next = new_unit;

	new_unit->value = _value;
	new_unit->next = NULL;

	return root;
}

void scanfLst(int_unit* root, int n) {
	int t;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &t);
		append(root, t);
	}
}

void deleteLst(int_unit* root) {
	int_unit* temp = root;

	while (root) {
		temp = root->next;
		delete root;

		root = temp;
	}
}

int printIntLst(int_unit* root) {
	int count = 0;

	while (root) {
		printf("%d ", root->value);
		root = root->next;

		count++;
	}
	printf("\n");

	return count;
}

int_unit* appbeg(int_unit* root, int _value) {
	int_unit* new_root = new int_unit;
	new_root->value = _value;
	new_root->next = root;

	return new_root;
}

int_unit* extend(int_unit* root, int_unit* addition) {
	int_unit* cur = root;

	while (cur->next) {
		cur = cur->next;
	}

	cur->next = addition;

	return root;
}

int_unit* insert(int_unit* root, int pr_value, int ins_value) {
	int_unit* cur = root;

	while (cur->value != pr_value && cur->next) {
		cur = cur->next;
	}

	if (cur->value == pr_value) {
		int_unit* nw = new int_unit;
		nw->value = ins_value;
		nw->next = cur->next;

		cur->next = nw;
	}

	return root;
}

int_unit* search(int_unit* root, int _value) {
	while (root->value != _value && root->next) {
		root = root->next;
	}

	return root->value == _value ? root : NULL;
}

int_unit* deleteUnit(int_unit* root, int _value) {
	int_unit* cur = root;
	int_unit* pr = NULL;

	while (cur->value != _value && cur->next) {
		pr = cur;
		cur = cur->next;
	}

	if (cur->value == _value) {
		if (cur == root) {
			root = cur->next;
			delete cur;
		}
		else {
			pr->next = cur->next;
			delete cur;
		}
	}

	return root;
}

int_unit* insert(int_unit* root, int pr_value, int_unit* ins_root) {
	int_unit* cur = root;

	while (cur->value != pr_value && cur->next) {
		cur = cur->next;
	}

	if (cur->value == pr_value) {
		int_unit* t = cur->next;
		cur->next = ins_root;

		int_unit* ins_cur = ins_root;
		while (ins_cur->next) {
			ins_cur = ins_cur->next;
		}
		ins_cur->next = t;
	}

	return root;
}

int_unit* reverse(int_unit* root) {
	int_unit* cur = root, * pr = NULL, * t;

	while (cur) {
		t = cur->next;
		cur->next = pr;
		pr = cur;
		cur = t;
	}

	return pr;
}

int main() {
	int_unit* test = init(0);
	scanfLst(test, 2);
	int_unit* test1 = init(0);
	scanfLst(test1, 2);

	printIntLst(test);
	printIntLst(test1);

	insert(test, 2, test1);

	printIntLst(test);
	printIntLst(test1);

	test = reverse(test);

	printIntLst(test);

	deleteLst(test);

	return 0;
}