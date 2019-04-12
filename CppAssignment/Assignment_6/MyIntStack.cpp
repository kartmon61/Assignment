#include "MyIntStack.h"

MyIntStack::MyIntStack() {
	for (int i = 0; i < 10; i++) {
		p[i] = 0;
	}
	tos = -1;
}

bool MyIntStack::push(int n) {
	if (tos > 8) {
		return false;
	}
	
	p[++tos] = n;

	return true;
}

bool MyIntStack::pop(int &n) {
	if (tos == -1) {
		return false;
	}
	else {
		n = p[tos--];

		return true;
	}
	

}