#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class HeapSort : public QObject
{
    Q_OBJECT

public:
    explicit HeapSort(MainWindow *visual);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    void shiftDown(int low, int high);

    MainWindow *visual;
    ArrayToSort &array;
};

#endif // HEAPSORT_H
