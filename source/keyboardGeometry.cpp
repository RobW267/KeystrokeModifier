#include "keyboardGeometry.h"
#include <Windows.h>

double dRand() {
	return ((double)rand()) / RAND_MAX;
}

KeyboardGeometry::KeyboardGeometry() {
	keyboard.addCon(VK_OEM_3, '1');
	keyboard.addCon(VK_OEM_3, VK_TAB);
	keyboard.addCon('1', '2');
	keyboard.addCon('1', VK_TAB);
	keyboard.addCon('1', 'Q');
	keyboard.addCon('2', '3');
	keyboard.addCon('2', 'Q');
	keyboard.addCon('2', 'W');
	keyboard.addCon('3', '4');
	keyboard.addCon('3', 'W');
	keyboard.addCon('3', 'E');
	keyboard.addCon('4', '5');
	keyboard.addCon('4', 'E');
	keyboard.addCon('4', 'R');
	keyboard.addCon('5', '6');
	keyboard.addCon('5', 'R');
	keyboard.addCon('5', 'T');
	keyboard.addCon('6', '7');
	keyboard.addCon('6', 'T');
	keyboard.addCon('6', 'Y');
	keyboard.addCon('7', '8');
	keyboard.addCon('7', 'Y');
	keyboard.addCon('7', 'U');
	keyboard.addCon('8', '9');
	keyboard.addCon('8', 'U');
	keyboard.addCon('8', 'I');
	keyboard.addCon('9', '0');
	keyboard.addCon('9', 'I');
	keyboard.addCon('9', 'O');
	keyboard.addCon('0', VK_OEM_MINUS);
	keyboard.addCon('0', 'O');
	keyboard.addCon('0', 'P');
	keyboard.addCon(VK_OEM_MINUS, VK_OEM_PLUS);
	keyboard.addCon(VK_OEM_MINUS, 'P');
	keyboard.addCon(VK_OEM_MINUS, VK_OEM_4);
	keyboard.addCon(VK_OEM_PLUS, VK_BACK);
	keyboard.addCon(VK_OEM_PLUS, VK_OEM_4);
	keyboard.addCon(VK_OEM_PLUS, VK_OEM_6);
	keyboard.addCon(VK_BACK, VK_OEM_6);
	keyboard.addCon(VK_BACK, VK_OEM_5);
	keyboard.addCon(VK_TAB, 'Q');
	keyboard.addCon(VK_TAB, VK_CAPITAL);
	keyboard.addCon('Q', 'W');
	keyboard.addCon('Q', VK_CAPITAL);
	keyboard.addCon('Q', 'A');
	keyboard.addCon('W', 'E');
	keyboard.addCon('W', 'A');
	keyboard.addCon('W', 'S');
	keyboard.addCon('E', 'R');
	keyboard.addCon('E', 'S');
	keyboard.addCon('E', 'D');
	keyboard.addCon('R', 'T');
	keyboard.addCon('R', 'D');
	keyboard.addCon('R', 'F');
	keyboard.addCon('T', 'Y');
	keyboard.addCon('T', 'F');
	keyboard.addCon('T', 'G');
	keyboard.addCon('Y', 'U');
	keyboard.addCon('Y', 'G');
	keyboard.addCon('Y', 'H');
	keyboard.addCon('U', 'I');
	keyboard.addCon('U', 'H');
	keyboard.addCon('U', 'J');
	keyboard.addCon('I', 'O');
	keyboard.addCon('I', 'J');
	keyboard.addCon('I', 'K');
	keyboard.addCon('O', 'P');
	keyboard.addCon('O', 'K');
	keyboard.addCon('O', 'L');
	keyboard.addCon('P', VK_OEM_4);
	keyboard.addCon('P', 'L');
	keyboard.addCon('P', VK_OEM_1);
	keyboard.addCon(VK_OEM_4, VK_OEM_6);
	keyboard.addCon(VK_OEM_4, VK_OEM_1);
	keyboard.addCon(VK_OEM_4, VK_OEM_7);
	keyboard.addCon(VK_OEM_6, VK_OEM_5);
	keyboard.addCon(VK_OEM_6, VK_OEM_7);
	keyboard.addCon(VK_OEM_6, VK_RETURN);
	keyboard.addCon(VK_OEM_5, VK_RETURN);
	keyboard.addCon(VK_CAPITAL, 'A');
	keyboard.addCon(VK_CAPITAL, VK_LSHIFT);
	keyboard.addCon('A', 'S');
	keyboard.addCon('A', VK_LSHIFT);
	keyboard.addCon('A', 'Z');
	keyboard.addCon('S', 'D');
	keyboard.addCon('S', 'Z');
	keyboard.addCon('S', 'X');
	keyboard.addCon('D', 'F');
	keyboard.addCon('D', 'X');
	keyboard.addCon('D', 'C');
	keyboard.addCon('F', 'G');
	keyboard.addCon('F', 'C');
	keyboard.addCon('F', 'V');
	keyboard.addCon('G', 'H');
	keyboard.addCon('G', 'V');
	keyboard.addCon('G', 'B');
	keyboard.addCon('H', 'J');
	keyboard.addCon('H', 'B');
	keyboard.addCon('H', 'N');
	keyboard.addCon('J', 'K');
	keyboard.addCon('J', 'N');
	keyboard.addCon('J', 'M');
	keyboard.addCon('K', 'L');
	keyboard.addCon('K', 'M');
	keyboard.addCon('K', VK_OEM_COMMA);
	keyboard.addCon('L', VK_OEM_1);
	keyboard.addCon('L', VK_OEM_COMMA);
	keyboard.addCon('L', VK_OEM_PERIOD);
	keyboard.addCon(VK_OEM_1, VK_OEM_7);
	keyboard.addCon(VK_OEM_1, VK_OEM_PERIOD);
	keyboard.addCon(VK_OEM_1, VK_OEM_2);
	keyboard.addCon(VK_OEM_7, VK_RETURN);
	keyboard.addCon(VK_OEM_7, VK_OEM_2);
	keyboard.addCon(VK_OEM_7, VK_RSHIFT);
	keyboard.addCon(VK_RETURN, VK_RSHIFT);
	keyboard.addCon(VK_LSHIFT, 'Z');
	keyboard.addCon(VK_LSHIFT, VK_LCONTROL);
	keyboard.addCon(VK_LSHIFT, VK_LWIN);
	keyboard.addCon('Z', 'X');
	keyboard.addCon('Z', VK_LWIN);
	keyboard.addCon('Z', VK_LMENU);
	keyboard.addCon('X', 'C');
	keyboard.addCon('X', VK_LMENU);
	keyboard.addCon('X', VK_SPACE);
	keyboard.addCon('C', 'V');
	keyboard.addCon('C', VK_SPACE);
	keyboard.addCon('V', 'B');
	keyboard.addCon('V', VK_SPACE);
	keyboard.addCon('B', 'N');
	keyboard.addCon('B', VK_SPACE);
	keyboard.addCon('N', 'M');
	keyboard.addCon('N', VK_SPACE);
	keyboard.addCon('M', ',');
	keyboard.addCon('M', VK_SPACE);
	keyboard.addCon(',', '.');
	keyboard.addCon(',', VK_SPACE);
	keyboard.addCon(',', VK_RMENU);
	keyboard.addCon('.', '/');
	keyboard.addCon('.', VK_RMENU);
	keyboard.addCon('.', VK_RCONTROL);
	keyboard.addCon('/', VK_RSHIFT);
	keyboard.addCon('/', VK_RCONTROL);
	keyboard.addCon(VK_RSHIFT, VK_RCONTROL);
	keyboard.addCon('M', VK_SPACE);
	keyboard.addCon(VK_LCONTROL, VK_LWIN);
	keyboard.addCon(VK_LWIN, VK_LMENU);
	keyboard.addCon(VK_LMENU, VK_SPACE);
	keyboard.addCon(VK_SPACE, VK_RMENU);
	keyboard.addCon(VK_RMENU, VK_RCONTROL);
	keyboard.addCon(VK_INSERT, VK_HOME);
	keyboard.addCon(VK_INSERT, VK_DELETE);
	keyboard.addCon(VK_HOME, VK_PRIOR);
	keyboard.addCon(VK_HOME, VK_END);
	keyboard.addCon(VK_PRIOR, VK_NEXT);
	keyboard.addCon(VK_DELETE, VK_END);
	keyboard.addCon(VK_END, VK_NEXT);
	keyboard.addCon(VK_UP, VK_DOWN);
	keyboard.addCon(VK_LEFT, VK_DOWN);
	keyboard.addCon(VK_DOWN, VK_RIGHT);
	keyboard.addCon(VK_NUMLOCK, VK_DIVIDE);
	keyboard.addCon(VK_NUMLOCK, VK_NUMPAD7);
	keyboard.addCon(VK_DIVIDE, VK_MULTIPLY);
	keyboard.addCon(VK_DIVIDE, VK_NUMPAD8);
	keyboard.addCon(VK_MULTIPLY, VK_SUBTRACT);
	keyboard.addCon(VK_MULTIPLY, VK_NUMPAD9);
	keyboard.addCon(VK_SUBTRACT, VK_ADD);
	keyboard.addCon(VK_NUMPAD7, VK_NUMPAD8);
	keyboard.addCon(VK_NUMPAD7, VK_NUMPAD4);
	keyboard.addCon(VK_NUMPAD8, VK_NUMPAD9);
	keyboard.addCon(VK_NUMPAD8, VK_NUMPAD5);
	keyboard.addCon(VK_NUMPAD9, VK_ADD);
	keyboard.addCon(VK_NUMPAD9, VK_NUMPAD6);
	keyboard.addCon(VK_NUMPAD4, VK_NUMPAD5);
	keyboard.addCon(VK_NUMPAD4, VK_NUMPAD1);
	keyboard.addCon(VK_NUMPAD5, VK_NUMPAD6);
	keyboard.addCon(VK_NUMPAD5, VK_NUMPAD2);
	keyboard.addCon(VK_NUMPAD6, VK_ADD);
	keyboard.addCon(VK_NUMPAD6, VK_NUMPAD3);
	keyboard.addCon(VK_ADD, VK_RETURN);
	keyboard.addCon(VK_NUMPAD1, VK_NUMPAD2);
	keyboard.addCon(VK_NUMPAD1, VK_NUMPAD0);
	keyboard.addCon(VK_NUMPAD2, VK_NUMPAD3);
	keyboard.addCon(VK_NUMPAD2, VK_NUMPAD0);
	keyboard.addCon(VK_NUMPAD3, VK_RETURN);
	keyboard.addCon(VK_NUMPAD0, VK_DECIMAL);
	keyboard.addCon(VK_DECIMAL, VK_RETURN);
}

KeyboardGeometry::~KeyboardGeometry() {

}


void KeyboardGeometry::beginMap(unsigned char key) {
	GeometryE* ptr = &keyboard.geometry[key];
	while (dRand() < 0.0625) {
		if (ptr->neighbors.empty()) continue;
		unsigned int nId = rand() % ptr->neighbors.size();
		ptr = ptr->neighbors[nId];
	}
	keyboard.geometry[key].map = ptr;
}


void KeyboardGeometry::endMap(unsigned char key) {
	keyboard.geometry[key].map = nullptr;
}


unsigned char KeyboardGeometry::getMap(unsigned char key) {
	if (!keyboard.geometry[key].map) beginMap(key);
	return (keyboard.geometry[key].map - keyboard.geometry);
}
