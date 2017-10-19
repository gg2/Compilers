#include"RPNCalc.h"

RPNCalc::RPNCalc() {
	DOUBLE_PRECISION = 16;
	ERR_INSUFFICIENT = "Insufficient input to do the calculation!";
	MSG_EMPTY = "<empty>";
}

void RPNCalc::store(double d) {
	stack.push(d);
}

void RPNCalc::add() {
	if (stack.count() > 1) {
		stack.push(stack.pop() + stack.pop());
	} else {
		std::cout << ERR_INSUFFICIENT << "\n";
	}
}
void RPNCalc::subtract() {
	if (stack.count() > 1) {
		double x = stack.pop();
		stack.push(stack.pop() - x);
	} else {
		std::cout << ERR_INSUFFICIENT << "\n";
	}
}
void RPNCalc::multiply() {
	if (stack.count() > 1) {
		stack.push(stack.pop() * stack.pop());
	} else {
		std::cout << ERR_INSUFFICIENT << "\n";
	}
}
void RPNCalc::divide() {
	if (stack.count() > 1) {
		double x = stack.pop();
		if (x == 0.0) {
			stack.pop();
			std::cout << "Division by zero!\n"; 
		} else {
			stack.push(stack.pop() / x);
		}
	} else {
		std::cout << ERR_INSUFFICIENT << "\n";
	}
}

void RPNCalc::sq() {
	if (stack.count() > 0) {
		double x = stack.pop();
		stack.push(x * x);
	} else {
		std::cout << ERR_INSUFFICIENT << "\n";
	}
}
void RPNCalc::sqrt() {
	if (stack.count() > 0) {
		// Do not allow negatives when taking square root
		double x = stack.pop();
		if (x < 0.0) {
			std::cout << "Square root domain error: negative radicand!\n"; 
		} else {
			stack.push(std::sqrt(x));
		}
	} else {
		std::cout << ERR_INSUFFICIENT << "\n";
	}
}

void RPNCalc::dup() {
	if (stack.count() > 0) {
		stack.push(stack.top());
	} else {
		std::cout << "Nothing to duplicate!\n";
	}
}
void RPNCalc::swap() {
	if (stack.count() > 1) {
		double d1, d2;
		d1 = stack.pop();
		d2 = stack.pop();
		stack.push(d1);
		stack.push(d2);
	} else {
		std::cout << "Insufficient items to swap!\n";
	}
}

std::string RPNCalc::ps() {
	std::string msg;
	if (stack.count() < 1) {
		msg = MSG_EMPTY;
	} else {
		msg = stack.print();
	}
	return msg;
}
std::string RPNCalc::result() {
	std::string msg;
	if (stack.count() < 1) {
		msg = MSG_EMPTY;
	} else {
		std::ostringstream ss;
		ss.precision(DOUBLE_PRECISION);
		ss << stack.top();
		msg = ss.str();
	}
	return msg;
}
