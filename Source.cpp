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

class blocks {
private:

	bool T1[3][3] = {
		{0,1,0,},
		{1,1,0,},
		{0,1,0,}
	};

	bool T2[3][3] = {
		{0,1,0,},
		{1,1,1,},
		{0,0,0,}
	};

	bool T3[3][3] = {
		{1,0,0,},
		{1,1,0,},
		{1,0,0,}
	};

	bool T4[3][3] = {
		{1,1,1,},
		{0,1,0,},
		{0,0,0,}
	};

	bool L1[3][3] = {
	{1,1,1,},
	{1,0,0,},
	{0,0,0,}
	};

	bool L2[3][3] = {
	{1,1,0,},
	{0,1,0,},
	{0,1,0,}
	};

	bool L3[3][3] = {
	{0,0,1,},
	{1,1,1,},
	{0,0,0,}
	};

	bool L4[3][3] = {
	{1,0,0,},
	{1,0,0,},
	{1,1,0,}
	};

	bool J1[3][3] = {
	{1,0,0,},
	{1,1,1,},
	{0,0,0,}
	};

	bool J2[3][3] = {
	{1,1,0,},
	{1,0,0,},
	{1,0,0,}
	};

	bool J3[3][3] = {
	{1,1,1,},
	{0,0,1,},
	{0,0,0,}
	};

	bool J4[3][3] = {
	{0,1,0,},
	{0,1,0,},
	{1,1,0,}
	};

	bool S1[3][3] = {
	{1,0,0,},
	{1,1,0,},
	{0,1,0,}
	};

	bool S2[3][3] = {
	{0,1,1,},
	{1,1,0,},
	{0,0,0,}
	};

	bool Z1[3][3] = {
	{0,1,0,},
	{1,1,0,},
	{1,0,0,}
	};

	bool Z2[3][3] = {
	{1,1,0,},
	{0,1,1,},
	{0,0,0,}
	};

	bool L[4]{ 1 };
	bool O[2][2]{ 1 };

public:
	void through() {
		print(T1);
		print(T2);
		print(T3);
		print(T4);
		print(L1);
		print(L2);
		print(L3);
		print(L4);
		print(J1);
		print(J2);
		print(J3);
		print(J4);
		print(S1);
		print(S2);
		print(Z1);
		print(Z2);
		//print(L1);
	}

	void print(bool matrix[][3] ) {
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j < 3; j++) {
				cout <<  matrix[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

class TerrisBoard {
private:
	raw* head, * tail, * here;
	int high, width, *floor;

public:
	blocks block;

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
	bool** init_shape(int x, int y);

};

int main() {
	
	cout << "hello world" << endl;

	TerrisBoard TB(4, 5);
	TB.block.through();
	//TB.board_out();

	return(0);
}


/*
bool** init_shape(int x, int y) {
	bool** model = 0;
	model = new bool* [x];
	for (int i = 0; i < x; i++) {
		model[i] = new bool[y];
	}
	return(model);
}

bool** TerrisBoard::shape(char Case, int rotation) {
	bool** model = 0;
	if (Case == 'T') {
		if (rotation == 1) {
			model = TerrisBoard::init_shape(3, 2);
		}
		else if (rotation == 2){
			model = TerrisBoard::init_shape(2, 3);
		}
		else if (rotation == 3){
			model = TerrisBoard::init_shape(3, 2);
		}
		else{
			model = TerrisBoard::init_shape(2, 3);
		}
	}
	else if (Case == 'L') {
		if (rotation == 1) {
			model = TerrisBoard::init_shape(2, 3);
		}
		else if (rotation == 2) {
			model = TerrisBoard::init_shape(3, 2);
		}
		else if (rotation == 3) {
			model = TerrisBoard::init_shape(2, 3);
		}
		else {
			model = TerrisBoard::init_shape(3, 2);
		}

	}
	else if (Case == 'J') {
		if (rotation == 1) {
			model = TerrisBoard::init_shape(2, 3);
		}
		else if (rotation == 2) {
			model = TerrisBoard::init_shape(3, 2);
		}
		else if (rotation == 3) {
			model = TerrisBoard::init_shape(2, 3);
		}
		else {
			model = TerrisBoard::init_shape(3, 2);
		}

	}
	else if (Case == 'S') {
		if (rotation == 1) {
			model = TerrisBoard::init_shape(3, 2);
		}
		else {
			model = TerrisBoard::init_shape(2, 3);
		}

	}
	else if (Case == 'Z') {
		if (rotation == 1) {
			model = TerrisBoard::init_shape(3, 2);
		}
		else {
			model = TerrisBoard::init_shape(2, 3);
		}

	}
	else{
		model = TerrisBoard::init_shape(2,2);
	}
}
*/