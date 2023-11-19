// MnojestvaDzOOP.cpp 

#include "Mnojestva.h"

int main()
{
    setlocale(NULL, "RU");
    srand(time(NULL));
    int proverka{}, vod{};
    cout << "Из скольки чисел должно состоять множество: "; cin >> vod;


    Mnojesta a(vod);
    Mnojesta b(a);

    cout << endl;

    cout << "Введите число которое хотите найти: ";

    cin >> proverka;
    cout << endl;
    if (a.element(proverka)|| b.element(proverka))
    {
        cout << "Число " << proverka << " присутствует в множестве." << endl;
    }
    else 
    {
        cout << "Число " << proverka << " отсутствует в множестве." << endl;
    }
   

    // Это так для прмиера есил что можете свои значение подставить и проверить, 
    // лень делать пользовательский ввод + долго
    // еще проблемы с пересечением, с сравнением в никакиую не хотят работать
    // ввод и вывод так же

    // Добавляем элемент в множество 
    a += 6;

    // Объединяем множества 
    Mnojesta c1 = a + b;
    
    // Удаляем элемент из множества 
    a -= 6;

    // Находим разность множеств 
    Mnojesta c2 = a - b;

    // Присваиваем множеству 
    a = b;

    

   
}
    


