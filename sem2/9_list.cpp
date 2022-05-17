#include <stdio.h>
#include <clocale>

struct int_unit {
	int value;
	int_unit* next;
};

void printLists() {
	int i = 1;
	printf("%d создать список\n", i++);
	printf("%d добавить элемент в конец\n", i++);
	printf("%d добавить элемент в начало\n", i++);
	printf("%d добавить элемент в середину\n", i++);
	printf("%d добавить элемент в отсортированный список\n", i++);
	printf("%d расширить список\n", i++);
	printf("%d найти элемент\n", i++);
	printf("%d удалить элемент\n", i++);
	printf("%d вставить список\n", i++);
	printf("%d развернуть список\n", i++);
	printf("%d напечатать список\n", i++);
	printf("%d выход\n", i++);
}

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

	while (cur || cur->value != _value) {
		pr = cur;
		cur = cur->next;
	}

	if (cur->value == _value) {
		if (cur == root) {
			root = cur->next;
		}
		else {
			pr->next = cur->next;
		}

		delete cur;
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

int_unit*  insertSorted(int_unit* root, int _value) {
	int_unit* cur = root;
	int_unit* pr = cur;
	int_unit* p = new int_unit;
	p->value = _value;

	while (cur && cur->value < _value) {
		pr = cur;
		cur = cur->next;
	}

	return root;
}


int main() {
	setlocale(LC_ALL, "");
	bool cycle = true;
	int nLists;
	int n;
	int_unit* lst = init(0);

	printLists();

	while (cycle) {
		printf("номер операции: ");  scanf_s("%d", &nLists);

		switch (nLists) {
		case 1: {
			printf("первое значение: ");  scanf_s("%d", &n);
			deleteLst(lst);
			lst = init(n);
			break;
		}
		case 2: {
			printf("значение: ");  scanf_s("%d", &n);
			append(lst, n);
			break;
		}
		case 3: {
			printf("значение: "); scanf_s("%d", &n);
			lst = appbeg(lst, n);
			break;
		}
		case 4: {
			printf("значение: "); scanf_s("%d", &n);
			printf("значение, после которого вставится первое: "); int pr; scanf_s("%d", &pr);
			insert(lst, pr, n);
			break;
		}
		case 5: {
			printf("значение: "); scanf_s("%d", &n);
			insertSorted(lst, n);
			break;
		}
		case 6: {
			printf("количество значений: "); scanf_s("%d", &n);
			scanfLst(lst, n);
			break;
		}
		case 7: {
			printf("значение: "); scanf_s("%d", &n);
			printIntLst(search(lst, n));
			break;
		}
		case 8: {
			printf("значение: "); scanf_s("%d", &n);
			deleteUnit(lst, n);
			break;
		}
		case 9: {
			printf("новый список: \n");
			scanf_s("%d", &n);
			int_unit* add = init(n);
			scanfLst(add, n - 1);

			printf("значение: ");  scanf_s("%d", &n);
			insert(lst, n, add);

			break;
		}
		case 10: {
			lst = reverse(lst);
			break;
		}
		case 11: {
			printIntLst(lst);
			break;
		}
		case 12: {
			cycle = false;
			break;
		}
		default: {
			printf("wrong\n");
		}
		}
		
	}

	deleteLst(lst);

	return 0;
}