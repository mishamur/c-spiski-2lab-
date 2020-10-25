/*Дано
В некоторой строке могут быть скобки трёх типов - круглые ( ), квадратные [ ] и фигурные { }. 
За один проход по строке проверить, сбалансирована ли строка по скобкам?
Смоделировать и использовать в программе стек.

*/

#include <iostream>
#include <locale>

using namespace std;



struct List
{
	char info;
	List * pred, *next;
};

// Функция исключает элемент р из списка, возвращает указатель на
// элемент, следовавший после него
List * removeElement(List *p)
{
	if (p)
	{
		List * p1 = p->pred;
		List * p2 = p->next;
		p1->next = p2;
		p2->pred = p1;
		p->pred = p->next = NULL;
		return p2;
	}
	else
		return NULL;
}

// Функция создает двусвязный список из n элементов с двумя сторожами
// Через head возвращает указатель на головного сторожа, 
// через tail - на хвостового сторожа
void createRandomList(List * &head, List * &tail, int n)
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;

	List * last = head;
	//srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		char number;
		cin >> number;
		List * p = new List;
		//p->info = rand() % 200 - 100;
		p->info = number;
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
		
	}

	return;
}




void insertElementPredLast(List *&last, List *&p) {
	p->pred = last;
	p->next = last->next;
	last->next = p;
	p->next->pred = p;
	return;
}


bool test(List *&head, List *&tail, string stroke) {
	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;

	List *last = head;

	List *p = new List;
	p->info = stroke[0];
	insertElementPredLast(last, p);

	for (int i = 1; i < stroke.length(); i++) {
		switch (stroke[i])
		{
		case '[':
		case '{':
		case '(':
		

			List * p = new List;
			p->info = stroke[i];
			insertElementPredLast(last, p);
			/*p->pred = last;
			p->next = last->next;
			last->next = p;
			p->next->pred = p;*/
			break;
		}

		switch (stroke[i])
		{
		case ']':
		case '}':
		case ')':
			if (head->next = tail) {
				return 0;
			}
			p->pred->next = p->next;
			p->next->pred = p->pred;
			List *q = p->pred;
			delete p;
			p = q;
			
		}
	}
	if (head->next = tail) {
		return 1;
	}
	else {
		return 0;
	}

}

//вывод списка(стека)
void printList(List *head, List *tail) {
	if (head) {
		List *p = head->next;
		while (p != tail) {
			cout << p->info << "\n";
			p = p->next;
		}
		cout << endl;
	}

	
}



int main() {
	setlocale(LC_ALL, "RUS");
	
	List *head = nullptr; List *tail = nullptr;
	//createRandomList(head, tail, 5);
	//printList(head, tail);

	string stroke;
	//cin >> stroke;
	stroke = "([]})";

	cout << stroke << endl;
	cout << stroke.length();
	cout << "\n \n \n \n  ======================================================================================= \n\n\n\n";
	
	//test(head, tail, stroke);
	printList(head, tail);

	if (test(head, tail, stroke)) {
		cout << "Всё нормально ";
	}
	else {
		cout << "Не нормально";
	}

	return 0;
}