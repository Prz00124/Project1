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
			/*if (d[i]) cout << 1 << " ";
			else cout << 0 << " ";*/
			cout << d[i] << " ";
		}
		cout <<" :"<< score << endl;
	}
};
//gives array[n_column] with raw score

class cube {
public:
	bool shape[3][3]{ 0 }, empty[3]{ 0 };
	int lower[3]{ 0 }, higher[3]{ 3,3,3 };

	void get_cube(bool k[3][3]) {
		for (int i = 0; i < 3; i++) {
			bool check = true;//to see if there is any true value in this column
			for (int j = 0; j < 3; j++) {
				if (check && k[i][j]){
					lower[i] = j;  //when 1st time met true value,
					check = false; //set the index to lower
				}
				else if ((!check) && (!k[i][j])) {//when when met false again before end of column,
					if (higher[i] == 3) {
						higher[i] = j;            //set the index to higher
					}
				}
				shape[i][j] = k[i][j];
			}
			if (check) { //no true value in this column
				empty[i] = true;
			}/*
			else { //there is some true value in this column
				if (lower[i]>max){
					max = lower[i];
				}
			}*/
		}
	}
	//initialize cubes with given value

	void print() {
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j < 3; j++) {
				cout << shape[j][i] << " ";
			}
			cout << endl;
		}
		cout << "empty: " << empty[0] << " " << empty[1] << " " << empty[2] << endl;
		cout << "lower: " << lower[0] << " " << lower[1] << " " << lower[2] << endl;
		cout << "highr: " << higher[0] << " " << higher[1] << " " << higher[2] << endl;
		cout << endl;
	}
};
//gives blank 3*3 matrix with empty[x],  lower bound[x], higher bound[x]

class blocks {
public:
	cube T1, T2, T3, T4, L1, L2, L3, L4, J1, J2, J3, J4, S1, S2, Z1, Z2;

	void init() {
		bool t1[3][3] = {
			{0,1,0,},
			{1,1,0,},
			{0,1,0,}
		};
		T1.get_cube(t1);

		bool t2[3][3] = {
			{0,1,0,},
			{1,1,1,},
			{0,0,0,}
		};
		T2.get_cube(t2);

		bool t3[3][3] = {
			{1,0,0,},
			{1,1,0,},
			{1,0,0,}
		};
		T3.get_cube(t3);

		bool t4[3][3] = {
			{1,1,1,},
			{0,1,0,},
			{0,0,0,}
		};
		T4.get_cube(t4);

		bool l1[3][3] = {
		{1,1,1,},
		{1,0,0,},
		{0,0,0,}
		};
		L1.get_cube(l1);

		bool l2[3][3] = {
		{1,1,0,},
		{0,1,0,},
		{0,1,0,}
		};
		L2.get_cube(l2);

		bool l3[3][3] = {
		{0,0,1,},
		{1,1,1,},
		{0,0,0,}
		};
		L3.get_cube(l3);

		bool l4[3][3] = {
		{1,0,0,},
		{1,0,0,},
		{1,1,0,}
		};
		L4.get_cube(l4);

		bool j1[3][3] = {
		{1,0,0,},
		{1,1,1,},
		{0,0,0,}
		};
		J1.get_cube(j1);

		bool j2[3][3] = {
		{1,1,0,},
		{1,0,0,},
		{1,0,0,}
		};
		J2.get_cube(j2);

		bool j3[3][3] = {
		{1,1,1,},
		{0,0,1,},
		{0,0,0,}
		};
		J3.get_cube(j3);

		bool j4[3][3] = {
		{0,1,0,},
		{0,1,0,},
		{1,1,0,}
		};
		J4.get_cube(j4);

		bool s1[3][3] = {
		{1,0,0,},
		{1,1,0,},
		{0,1,0,}
		};
		S1.get_cube(s1);

		bool s2[3][3] = {
		{0,1,1,},
		{1,1,0,},
		{0,0,0,}
		};
		S2.get_cube(s2);

		bool z1[3][3] = {
		{0,1,0,},
		{1,1,0,},
		{1,0,0,}
		};
		Z1.get_cube(z1);

		bool z2[3][3] = {
		{1,1,0,},
		{0,1,1,},
		{0,0,0,}
		};
		Z2.get_cube(z2);
	}
	//set values to block
	
	void through() {
		print(T1.shape);
		
		print(T2.shape);
		print(T3.shape);
		print(T4.shape);
		print(L1.shape);
		print(L2.shape);
		print(L3.shape);
		print(L4.shape);
		print(J1.shape);
		print(J2.shape);
		print(J3.shape);
		print(J4.shape);
		print(S1.shape);
		print(S2.shape);
		print(Z1.shape);
		print(Z2.shape);
		//print(L1);
	}
	//print out all of 3*3 block in blocks by calling print defined below

	void print(bool matrix[][3] ) {
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j < 3; j++) {
				cout <<  matrix[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	//print out single given block
};
//gives is the set of all kinds of blocks

class TerrisBoard {
private:
	raw* head, * tail, * here;
	int high, width, *floor, half = 0;
	blocks block;

public:
	TerrisBoard(int nculomn, int nraw) {
		block.init();
		high = nraw;
		half = high / 2;
		width = nculomn;
		floor = new int[nculomn] {0};

		int k = 0;
		head = new raw(nculomn);
		//cout << "create a new raw " << ++k << endl;
		here = head;
		for (int i = 0; i < nraw-1; i++) {
			//cout << "create a new raw " << ++k << endl;
			here->next = new raw(nculomn);
			(here->next)->last = here;
			here = here->next;
		}

		tail = here;
		head->last = tail;
		tail->next = head;
		//here = head;
	}
	//initialize board

	void return_head() {
		here = head;
	}
	//return here pointer to 0 raw

	void go_to_y(int y) {
		return_head();
		if (y > half) {
			for (int i = 0; i < (high - y); i++) {
				here = here->last;
			}
		}
		else {
			for (int i = 0; i < y; i++) {
				here = here->next;
			}
		}
	}
	//put here pointer to 0 and then move it to y raw

	void floor_out() {
		for (int i = 0; i < width; i++) {
			cout << floor[i] << " ";
		}
		cout << " <-floor " << endl << endl;
	}

	void board_out() {
		return_head();
		floor_out();

		here = tail;
		while (!(here == head)) {
			here->print();
			here = here->last;
		}
		here->print();

		cout << "~~~~~~~~~~~~~~~~~~~" << endl;
	}
	//print whole board

	void add_raw() {
		here = new raw(width);
		here->next = head;
		here->last = tail;
		head->last = here;
		tail->next = here;
		tail = here;
	}

	cube *char_to_cube(char input[2]) {
		if (input[0] == 'T') {
			if (input[1] == '1') {
				return &block.T1;
			}
			else if (input[1] == '2') {
				return &block.T2;
			}
			else if (input[1] == '3') {
				return &block.T3;
			}
			else {
				return &block.T4;
			}
		}
		else if (input[0] == 'L') {
			if (input[1] == '1') {
				return &block.L1;
			}
			else if (input[1] == '2') {
				return &block.L2;
			}
			else if (input[1] == '3') {
				return &block.L3;
			}
			else {
				return &block.L4;
			}
		}
		else if (input[0] == 'J') {
			if (input[1] == '1') {
				return &block.J1;
			}
			else if (input[1] == '2') {
				return &block.J2;
			}
			else if (input[1] == '3') {
				return &block.J3;
			}
			else {
				return &block.J4;
			}
		}
		else if (input[0] == 'S') {
			if (input[1] == '1') {
				return &block.S1;
			}
			else {
				return &block.S2;
			}
		}
		else if (input[0] == 'Z') {
			if (input[1] == '1') {
				return &block.Z1;
			}
			else {
				return &block.Z2;
			}
		}
		else if (input[0] == 'I') {

		}
		else {

		}
	}
	//decode char to cube type

	int first_down(cube *in_cube, int start_point, int channel) {
		int tem = 0, max = 0;
//		cout << "1st_down | x: " << start_point << " channel: " << channel << endl;
		for (int i = 0; i < channel; i++) {
			tem = floor[start_point + i] - in_cube->lower[i];
			if (tem>=max){
				max = tem;
			}
		}
//		cout << "1st_down return: " << max << endl;
		return max;
	}
	//1st cube down operater

	int second_down(cube* in_cube, int x, int y, int channel){
		int tem[3]{ 0 }, min = 64, y_plus = 0;
		go_to_y(y);
//		cout << "2nd input x: " << x << " y: " << y << endl;

		for (int i = 0; i < channel; i++) {
			raw* there = here;
			for (int j = 0; j < in_cube->lower[i]; j++) {
				there = there->next;
			}
			y_plus = y + in_cube->lower[i];
			while ((!there->last->d[x+i])&&(y_plus >tem[i])) {
				/*there->print();
				cout << endl;*/
				tem[i]++;
				there = there->last;
			}

			if (tem[i] < min) {
				min = tem[i];
			}
		}
		cout << endl;
		return(y - min);
	}
	//2nd cube down operater

	void paint(cube* in_cube, int x, int y) {
		go_to_y(y);

		for(int j=0;j<3;j++){
			for (int i = 0; i < 3; i++) {
				if (in_cube->shape[i][j]) {
					here->d[x + i] = true;
					here->score ++;
				}
			}
			here = here->next;
		}
	}
	//turn false to true with in_cube.shape on board

	bool cancel_rule(raw* target) {
		if (target->score == width) {
			
			target->last->next = target->next;
			target->next->last = target->last;
			if (target == head) {
				head = target->next;
			}
			else if (target == tail) {
				tail = target->last;
			}

			add_raw();
			here = target->next;
			delete target;
			
			return true;
		}
		else return false;
	}
	//delete a full raw

	int cancel_step(int y) {
		cout << "cancel_step input y: " << y << endl;
		int tem = 0;
		go_to_y(y);
		for (int i = 0; i < 3; i++) {
			if (cancel_rule(here)) {
				tem++;
			}
			else {
				here = here->next;
			}
		}
		
		if (tem) cout << "did canceld" << endl;
		return(tem);
	}
	//do 3 cancel operater from y

	int find_floor(int x, int start_point) {
		go_to_y(start_point);
		int tem = -1;
		while ((!here->d[x]) && !(here == head)) {
			here = here->last;
			tem++;
		}
		if (here == head && !here->d[x]) tem++;
		return(tem);
	}

	void refresh_floor(cube* in_cube ,int x, int y, int channel, int n_canceled) {
//		cout << "refresh_floor input x: " << x << " y: " << y << " channel: " << channel << " n_canceled: " << n_canceled << endl;
		for (int i = 0; i < channel; i++) {
			if (floor[x + i] < (y + in_cube->higher[i])) {
				floor[x + i] = y + in_cube->higher[i];
			}
		}

		//floor_out();

		if(n_canceled){
			for (int i = 0; i < width; i++) {
				if (floor[i] > y+3) {
					floor[i] -= n_canceled;
				}
				else if (floor[i] >= y) {
//					cout << 1;
					int tem = find_floor(i, floor[i]);
					floor[i] -= tem;
				}
			}
			cout << endl;
		}
	}

	void put_in(char type[2], int x_1, int x_2) {
		//x_1 --;
		//cout << "get x1 x2: " << x_1 << " " << x_2<<endl;

		int channel = 0, y = high, canceled = 0;
		cube* in_cube = char_to_cube(type);
		while (!in_cube->empty[channel]) {
			channel++;
			if (channel == 3) break;
		}
		//cout << "catch cube: " << endl;
		in_cube->print();
		//cout << "channel: " << channel << endl;

		y = first_down(in_cube, x_1, channel);
		//cout << "1st y: " << y << endl;
		if (x_2) {
			x_1 += x_2;
			y = second_down(in_cube, x_1, y, channel);
		}
		//if step requires 2nd shift, then update y
		paint(in_cube, x_1, y);

		/*cout << "tail: ";
		tail->print();
		cout << "head: ";
		head->print();*/

		canceled = cancel_step(y);

		refresh_floor(in_cube, x_1, y, channel, canceled);
	}

};
//the main structure

int main() {
	
	cout << "hello world" << endl;
	int x = 0, y = 0;
	char test[3];
	cin >> test;

	TerrisBoard TB(4, 10);

	//TB.block.through();
	TB.board_out();
	for (int i = 0; i < 4; i++) {
		TB.put_in(test, 0, 2);
		TB.board_out();
		TB.put_in(test, 0, 0);
		TB.board_out();
	}

	return(0);
}