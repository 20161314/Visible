#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"

class InsertSort : public QObject
{
    Q_OBJECT

public:
    InsertSort(MainWindow *visual);
    void startSort();

signals:
    void finished();

private:
    MainWindow *visual;
    ArrayToSort &array;

private slots:
    void runSort();
};

#endif // INSERTSORT_H
