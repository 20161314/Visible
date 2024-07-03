#include "ArrayToSort.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>

ArrayToSort::ArrayToSort()
{
    this->n = 100;
    this->arr.resize(100);
}

ArrayToSort::ArrayToSort(int num) : n(num)
{
    this->arr.resize(num);
}

void ArrayToSort::InitArray()
{
    for (int i = 0; i < n; i++) {
        this->arr[i] = i + 1;
    }
}

void ArrayToSort::SetSize(int num)
{
    this->arr.resize(num);
    this->n = num;
}

void ArrayToSort::ShuffleArray()
{
    std::shuffle(this->arr.begin(), this->arr.end(), std::default_random_engine(static_cast<unsigned>(time(nullptr))));
}

int ArrayToSort::get(int i) const
{
    if (i < 0 || i >= n) {
        std::cerr << "Got Error when using function 'get':\n";
        std::cerr << "Index out of range...\n";
        return 0;
    } else {
        return this->arr[i];
    }
}

void ArrayToSort::set(int temp, int i)
{
    if (i < 0 || i >= n) {
        std::cerr << "Got Error when using function 'set':\n";
        std::cerr << "Index out of range...\n";
    } else {
        this->arr[i] = temp;
    }
}
