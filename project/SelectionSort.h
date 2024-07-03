#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class SelectionSort : public QObject
{
    Q_OBJECT

public:
    explicit SelectionSort(MainWindow *visual);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    void swap(int i, int j);
    MainWindow *visual;
    ArrayToSort &array;
};

#endif // SELECTIONSORT_H
