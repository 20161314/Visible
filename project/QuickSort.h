#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class QuickSort : public QObject
{
    Q_OBJECT

public:
    explicit QuickSort(MainWindow *visual);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    int Partition(int s, int t);
    void _Qsort(int s, int t);

    MainWindow *visual;
    ArrayToSort &array;
};

#endif // QUICKSORT_H
