#include <iostream>
#include <string>
#include <windows.h>
#include <shellapi.h>

using namespace std;

string username;
string link = "https://www.brawlhalla.com/rankings/1v1/?p=";

int main(){
	cout << "Insert the username to search: " << endl;
	cin >> username;
	
	link += username;
	
	ShellExecute(NULL, "open", link.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
