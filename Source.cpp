#include<iostream>

using namespace std;

class raw {
public:
	bool* d;
	int score = 0, width;
	raw *last, * next;

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
	int high, width, * roof;

public:
	TerrisBoard(int nculomn, int nraw) {
		high = nraw;
		width = nculomn;
		roof = new int[nculomn];

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

};

int main() {
	
	cout << "hello world" << endl;

	TerrisBoard TB(4, 5);
	TB.board_out();

	return(0);
}