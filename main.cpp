#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;

	cout << "Enter Username: "; cin >> username;

	cout << "Enter Password: "; cin >> password;

	ifstream read("data\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
	if (choice == 1)
	{
		string username, password;

		cout << "Enter Username: "; cin >> username;

		cout << "Enter Password: "; cin >> password;

		ofstream file;

		file.open("data\\" + username + ".txt");

		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "You are not logged in" << endl;
			system("PAUSE");
			return 0;

		}
		else
		{
			cout << "You are already logged in" << endl;
			system("PAUSE");
			return 1;

		}
	}
}