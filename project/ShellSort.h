#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <QObject>
#include "mainwindow.h"
#include "arraytosort.h"
#include <QThread>
#include <QTimer>

class ShellSort : public QObject
{
    Q_OBJECT

public:
    explicit ShellSort(MainWindow *visual);

    void startSort();

signals:
    void finished();

private slots:
    void runSort();

private:
    MainWindow *visual;
    ArrayToSort &array;
};

#endif // SHELLSORT_H
