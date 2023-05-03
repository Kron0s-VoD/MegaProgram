#include <iostream>
#include <windows.h>
#include <string>

class HackingPentagon
{
private:
    int CountNumberInLine;
    int DelayInMilliseconds;

    HANDLE hConsole;

    std::string GetIndent()
    {
        std::string indent = "";

        for (int i = 0; i < rand() % 1000; i++)
        {
            indent += " ";
        }

        return indent;
    }

    void DeleteScrollbarInConsole()
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;

        GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

        short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
        short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

        short scrBufferWidth = scrBufferInfo.dwSize.X;
        short scrBufferHeight = scrBufferInfo.dwSize.Y;        

        COORD newSize;
        newSize.X = scrBufferWidth;
        newSize.Y = winHeight;

        int Status = SetConsoleScreenBufferSize(hOut, newSize);

        GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    }

    void ChangeTextColorInConsole(int codeColor)
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, codeColor); 
    }

public:
    HackingPentagon(int CountNumberInLine, int DelayInMilliseconds)
    {
        this->CountNumberInLine = CountNumberInLine;
        this->DelayInMilliseconds = DelayInMilliseconds;
    }

    void Hacking()
    {
        DeleteScrollbarInConsole();
        ChangeTextColorInConsole(2); 

        while ( !(GetKeyState(VK_LSHIFT) & 0x8000) )
        {
            Sleep(DelayInMilliseconds);

            for(int i = 0; i < CountNumberInLine; i++)
            {   
                std::cout << GetIndent() << rand() % 100;
            }
            std::cout << std::endl;
        }

        ChangeTextColorInConsole(7); 
    }
};

int main()
{
    srand(time(NULL));

    HackingPentagon program = HackingPentagon(100, 50);
    program.Hacking();

    return 0;
}