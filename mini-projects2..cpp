#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Content 
{
public:
    string title;
    string platform;
    int views;
    string status;

    void input() 
	{
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter Platform (YouTube/Instagram): ";
        getline(cin, platform);

        cout << "Enter Views: ";
        cin >> views;

        cout << "Enter Status (Idea/Uploaded): ";
        cin.ignore();
        getline(cin, status);
    }
    void display(int index) 
	{
        cout << index << ". " << title << " | " << platform 
             << " | Views: " << views 
             << " | Status: " << status << endl;
    }
};

vector<Content> contents;
// ?? Save to File
void saveToFile() {
    ofstream file("data.txt");
    for (auto &c ; contents) 
	{
        file << c.title << endl;
        file << c.platform << endl;
        file << c.views << endl;
        file << c.status << endl;
    }
    file.close();
}
// ?? Load from File
void loadFromFile() 
{
    ifstream file("data.txt");
    Content c;

    while (getline(file, c.title)) 
	{
        getline(file, c.platform);
        file >> c.views;
        file.ignore();
        getline(file, c.status);
        contents.push_back(c);
    }
    file.close();
}
// ? Add Content
void addContent() 
{
    Content c;
    c.input();
    contents.push_back(c);
    saveToFile();
    cout << "? Content Added!\n";
}
// ?? Show Content
void showContent() 
{
    if (contents.empty()) 
	{
        cout << "No Content Available!\n";
        return;
    }

    for (int i = 0; i < contents.size(); i++) 
	{
        contents[i].display(i);
    }
}
// ?? Edit Content
void editContent() 
{
    int index;
    showContent();
    cout << "Enter index to edit: ";
    cin >> index;

    if (index >= 0 && index < contents.size 
	{
        contents[index].input();
        saveToFile();
        cout << "?? Content Updated!\n";
    } 
	{
        cout << "Invalid Index!\n";
    }
}
// ? Delete Content
void deleteContent() 
{
    int index;
    showContent();
    cout << "Enter index to delete: ";
    cin >> index;
    if (index >= 0 && index < contents.size) 
	{
        contents.erase(contents.begin() + index);
        saveToFile();
        cout << "? Content Deleted!\n";
    } 
	{
        cout << "Invalid Index!\n";
    }
}
// ?? Main Menu
int main() 
{
    loadFromFile();
    int choice;
    do 
	{
        cout << "\n===== Creator Dashboard Lite =====\n";
        cout << "1. Add Content\n";
        cout << "2. Show Content\n";
        cout << "3. Edit Content\n";
        cout << "4. Delete Content\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1: addContent(); break;
            case 2: showContent(); break;
            case 3: editContent(); break;
            case 4: deleteContent(); break;
            case 5: cout << "?? Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 5);
}
