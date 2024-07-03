#ifndef ARRAYTOSORT_H
#define ARRAYTOSORT_H

#include <vector>

class ArrayToSort {
public:
    ArrayToSort();
    ArrayToSort(int num);

    void InitArray();
    void SetSize(int num);
    void ShuffleArray();
    int get(int i) const;
    void set(int temp, int i);

    std::vector<int> arr;
    int n;
};

#endif // ARRAYTOSORT_H
