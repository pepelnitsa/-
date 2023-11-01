#include <iostream>
using namespace std;

enum {
    Default,
    Red,
    Green,
    Blue,
};

class Application {
private:
    static Application* instance;
    string title;

    Application()
    {
        title = "Title";
    }

public:
    static Application* GetInstance() {
        if (instance == nullptr) {
            instance = new Application();
        }
        return instance;
    }

    void StartRandomize() {
        srand(time(0));
        int randomNumber = rand() % 100 + 1;
        cout << "Generated random number: " << randomNumber << endl;
    }

    void SetTextColor(const int color) {
        switch (color) {
        case Default:
            cout << "\033[0m";
            break;

        case Red:
            cout << "\033[31m";
            break;

        case Green:
            std::cout << "\033[32m";
            break;

        case Blue:
            std::cout << "\033[34m";
            break;

        default:
            cout << "\033[0m";
            break;
        }
    }

    void SetTitle(const string& newTitle)
    {
        title = newTitle;
    }

    string GetTitle()const
    {
        return title;
    }
    void ClearScreen()
    {
        system("cls");
    }
};

Application* Application::instance = nullptr;

int main() {
    int ch, flag = 0;

    Application* app = Application::GetInstance();

    while (true)
    {
        cout << "1 - Create" << endl;
        cout << "2 - Get title" << endl;
        cout << "3 - Set title" << endl;
        cout << "4 - Get random number" << endl;
        cout << "5 - Set text color" << endl;
        cout << "6 - Clear screen" << endl;
        cout << "7 - Exit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            app->GetInstance();
            break;

        case 2:
            cout << app->GetTitle() << endl;
            break;

        case 3:
            app->SetTitle("Title");
            break;

        case 4:
            app->StartRandomize();
            break;

        case 5:
            app->SetTextColor(Blue);
            break;

        case 6:
            app->ClearScreen();
            break;

        case 7:
            flag = 1;
            break;
        }
        if (flag == 1)
            break;
    }


    return 0;
}