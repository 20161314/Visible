#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"

class BubbleSort : public QObject
{
    Q_OBJECT

public:
    BubbleSort(MainWindow *visual);
    void startSort();

signals:
    void finished();

private:
    MainWindow *visual;
    ArrayToSort &array;

private slots:
    void runSort();
};

#endif // BUBBLESORT_H
