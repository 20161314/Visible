#ifndef MERGESORT_H
#define MERGESORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class MergeSort : public QObject
{
    Q_OBJECT

public:
    explicit MergeSort(MainWindow *visual);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    void Merge(int low, int mid, int high);
    void _Msort(int s, int t);

    MainWindow *visual;
    ArrayToSort &array;
};

#endif // MERGESORT_H
