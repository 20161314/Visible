#ifndef BINARYSORT_H
#define BINARYSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"

class BinarySort : public QObject
{
    Q_OBJECT

public:
    BinarySort(MainWindow *visual);
    void startSort();

signals:
    void finished();

private:
    MainWindow *visual;
    ArrayToSort &array;

private slots:
    void runSort();
};

#endif // BINARYSORT_H
