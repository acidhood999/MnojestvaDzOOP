#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



class Mnojesta
{
protected:

	int* mno1;
    int Size;
    int random;

public:

    

	Mnojesta(int size)
	{
		mno1 = new int[size];
        Size = size;
     
        for (int i = 0; i < size; i++) 
        {
            do 
            {
                random = 1 + rand() % 100;
            } 
            while (count(mno1, mno1 + size, random) > 0);
            mno1[i] = random;
        }
        cout << endl;
        for (int i = 0; i < size; i++) 
        {
            cout << mno1[i] << " ";
        }
        cout <<"Сылка конструктор"<< mno1 <<endl;
	}
   
    Mnojesta(const Mnojesta& other) 
    {
       
        cout << endl;
        Size = other.Size;
        mno1 = new int[other.Size];
       
        for (int i = 0; i < other.Size; i++)
        {
            do
            {
                random = 1 + rand() % 100;
            } 
            while (count(mno1, mno1 + Size, random) > 0);
            mno1[i] = random;
        }

        for (int i = 0; i < other.Size; i++)
        {
            cout << mno1[i] << " ";
        }
        cout << "Сылка копирования" << mno1 << endl;

    }

    bool element(int element) 
    {
        for (int i = 0; i < Size; i++)
        {
            if (mno1[i] == element) 
            {
                return true;
            }
        }
        return false;
    }

    // Добавление элемента в множество
    Mnojesta& operator+=(int num) {
        int* temp = new int[Size + 1];
        for (int i = 0; i < Size; i++) {
            temp[i] = mno1[i];
        }
        temp[Size] = num;
        delete[] mno1;
        mno1 = temp;
        Size++;
        return *this;
    }

    // Объединение двух множеств
    Mnojesta operator+(const Mnojesta& other) const {
        Mnojesta result(*this);
        for (int i = 0; i < other.Size; i++) {
            if (!result.element(other.mno1[i])) {
                result += other.mno1[i];
            }
        }
        return result;
    }

    // Удаление элемента из множества
    Mnojesta& operator-=(int num) {
        int index = -1;
        for (int i = 0; i < Size; i++) {
            if (mno1[i] == num) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < Size - 1; i++) {
                mno1[i] = mno1[i + 1];
            }
            Size--;
        }
        return *this;
    }

    // Разность множеств
    Mnojesta operator-(const Mnojesta& other) const {
        Mnojesta result(*this);
        for (int i = 0; i < other.Size; i++) {
            if (result.element(other.mno1[i])) {
                result -= other.mno1[i];
            }
        }
        return result;
    }

    // Присваивание
    Mnojesta& operator=(const Mnojesta& other) {
        if (this != &other) {
            delete[] mno1;
            Size = other.Size;
            mno1 = new int[Size];
            for (int i = 0; i < Size; i++) {
                mno1[i] = other.mno1[i];
            }
        }
        return *this;
    }

    



    ~Mnojesta() {
        delete[] mno1;

    }
   
};
