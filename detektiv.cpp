#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int lamp, pistol, knife, phone;

    cout << "Дождь… Он, как обычно громко постукивает по крыше маленького деревянного домика. " << endl;
    cout << "Фургон подъехал к нему.Что там происходит? Не понять никому." << endl;

    cout << "- Вы находитесь в фургоне. Возьмите вещи, которые могут вам пригодиться: "<< endl;
    cout << "фонарик(1), пистолет(2), нож(3), телефон(4)." << endl;
    cout << "(учтите, можно взять лишь 2 вещи, через пробел)" << endl;

    cin >> lamp >> pistol >> knife >> phone;
}
