#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class RadixSort : public QObject
{
    Q_OBJECT

public:
    explicit RadixSort(MainWindow *visual);

    void startSort(int r = 10);

signals:
    void finished();

private slots:
    void runSort(int r);

private:
    int getd(int r);
    int geti(int key, int r, int i);

    MainWindow *visual;
    ArrayToSort &array;
};

#endif // RADIXSORT_H
