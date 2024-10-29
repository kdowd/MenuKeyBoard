
#include <iostream>
#include "Menu.h"

using namespace std;

void showMainMenu() {
	vector<string> menuOne = { "Create New User","List All Users","Send Email", "Logout", "Exit" };
	pair<int, string> userSeletion = getKeyboardInput(menuOne, "Use Arrows Keys and Enter to make a choice.\n");

	//cout << "Seletion Number = " << userSeletion.first << "\n";
	//cout << "Seletion Choice = " << userSeletion.second << "\n";

	switch (userSeletion.first) {
	case 0:
		cout << "new user" << endl;
		break;
	case 1:
		cout << "list all users" << endl;
		break;
	case 2:
		cout << "send email" << endl;
		break;
	case 3:
		cout << "logout" << endl;
		break;
	case 4:
		cout << "user exit" << endl;
		exit(0);
	default:
		cout << "Shouldn't get here...";
	}
}

int main()
{

	showMainMenu();

	system("pause");
}

