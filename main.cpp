#include <iostream>

#include "UniText.h"

using namespace std;

void Test(UniText *Translator, const std::string &Data);

int main()
{

    UniText *MyText = NULL;

    try
    {
        MyText = new UniText("data/deutsch.txt");
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
        if(MyText)
        {
            delete MyText;
            MyText = NULL;
        }
        return 1;
    }

    Test(MyText, "alles");

    try
    {
        MyText->LoadNewText("data/english.txt");
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
        delete MyText;
        MyText = NULL;
        return 1;
    }

    Test(MyText, "all");

    if(MyText)
    {
        delete MyText;
        MyText = NULL;
    }

    return 0;
}

void Test(UniText *Translator, const std::string &Data)
{
    int Gold = 10;
    int Life = 25;
    std::string Name;
    std::string Text;

    cout << Translator->Print("[Test]") << endl;
    cin >> Name;

    Text = Translator->Print("[Test2]");
    Translator->Replace(Text, "%S", Name);
    cout << Text << endl;

    Text = Translator->Print("[Thx]");
    Translator->Replace(Text, "%F", Data);
    cout << Text << endl;

    Text = Translator->Print("[Gold]");
    Translator->Replace(Text, "%N", Gold);
    cout << Text << endl;

    Text = Translator->Print("[Live]");
    Translator->Replace(Text, "%N", Life);
    Translator->Replace(Text, "%G", Gold);
    cout << Text << endl;

}
