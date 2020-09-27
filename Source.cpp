#include<iostream>
#include<string.h>
using namespace std;

class raw {
public:
	bool* d;
	int score = 0, width;
	raw *last = NULL, * next = NULL;

	raw(int nculomn) {
		width = nculomn;
		d = new bool[nculomn]{ false };
	}

	void print() {
		for (int i = 0; i < width; i++) {
			cout << d[i] << " ";
		}
		cout << endl;
	}
};

class TerrisBoard {
private:
	raw* head, * tail, * here;
	int high, width, *floor;

public:
	TerrisBoard(int nculomn, int nraw) {
		high = nraw;
		width = nculomn;
		floor = new int[nculomn] {0};

		head = new raw(nculomn);
		here = head;
		for (int i = 0; i < nculomn+1; i++) {
			here->next = new raw(nculomn);
			(here->next)->last = here;
			here = here->next;
		}
		tail = here;
		tail->next = head;
		head->last = tail;
	}

	void return_head() {
		here = head;
	}

	void board_out() {
		for (int i = 0; i < high + 2; i++) {
			here-> print();
			here = here->next;
		}
	}

	bool** shape(char Case, int rotation);

};

int main() {
	
	cout << "hello world" << endl;

	TerrisBoard TB(4, 5);
	TB.board_out();

	return(0);
}

bool** TerrisBoard::shape(char Case, int rotation) {
	bool** model = 0;
	if (Case == 'T') {
		if (rotation == 1) {}
		else if (rotation == 2){}
		else if (rotation == 3){}
		else{}
	}
	else if (Case == 'L') {
		if (rotation == 1) {}
		else if (rotation == 2) {}
		else if (rotation == 3) {}
		else {}

	}
	else if (Case == 'J') {
		if (rotation == 1) {}
		else if (rotation == 2) {}
		else if (rotation == 3) {}
		else {}

	}
	else if (Case == 'S') {
		if (rotation == 1) {}
		else {}

	}
	else if (Case == 'Z') {
		if (rotation == 1) {}
		else {}

	}
	else if (Case == 'I') {
		if (rotation == 1) {}
		else {}

	}
	else{}
}