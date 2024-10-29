#include "Menu.h"

using namespace std;
// ansi codes to control the console - ancient stuff but still works...
// some ansi codes here:https://tforgione.fr/posts/ansi-escape-codes/

void drawMenu(vector<string>& m) {
	for (const auto& i : m) {
		cout << " " << i << "\n";
	}
}

void drawHelpMessage(string& s) {
	if (s.size() <= 0) return;
	cout << s;
}

void addKeyPressDelay() {
	Sleep(100);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void cursorLineUp() {
	cout << "\x1b[A";
}

void cursorLineDown() {
	cout << "\x1b[B";
}

void cursorToMenuBottom(int n) {
	string thecommand = "\x1b[";
	thecommand.append(to_string(n)).append("B");
	cout << thecommand;
}

void cursorToMenuTop(int n) {
	string thecommand = "\x1b[";
	thecommand.append(to_string(n)).append("A");
	cout << thecommand;
}

pair<int, string> getKeyboardInput(vector<string>& menuChoices, string helpString) {
	int menuSize = menuChoices.size();
	int keyCounter = 0;


	drawHelpMessage(helpString);
	drawMenu(menuChoices);
	cursorToMenuTop(menuSize);




	while (true) {
		if ((GetAsyncKeyState(VK_UP) & 0x8000)) {

			if (keyCounter > 0) {
				keyCounter--;
				cursorLineUp();
				addKeyPressDelay();
			}

		}
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000)) {

			if (keyCounter < menuSize - 1) {
				keyCounter++;
				cursorLineDown();
				addKeyPressDelay();
			}
		}

		// user hits the return key - a selection
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			cursorToMenuBottom(menuSize - keyCounter);
			break;
		}

	}

	// return selection number and the choice to main()
	return make_pair(keyCounter, menuChoices[keyCounter]);

}