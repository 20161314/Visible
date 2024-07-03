#include "QuickSort.h"
#include <QThread>
#include <QTimer>

QuickSort::QuickSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void QuickSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &QuickSort::runSort);
    connect(this, &QuickSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void QuickSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    _Qsort(0, n - 1);

    QThread::msleep(2000);
    emit finished();
}

int QuickSort::Partition(int s, int t)
{
    int i = s, j = t;
    int base = array.get(s);
    while (i < j) {
        while (j > i && array.get(j) > base)
            j--;
        if (j > i) {
            array.set(array.get(j), i);
            i++;
        }

        QThread::msleep(5);
        visual->update();

        while (i < j && array.get(i) <= base)
            i++;
        if (i < j) {
            array.set(array.get(i), j);
            j--;
        }

        QThread::msleep(5);
        visual->update();
    }
    array.set(base, i);
    QThread::msleep(5);
    visual->update();
    return i;
}

void QuickSort::_Qsort(int s, int t)
{
    if (s < t) {
        int i = Partition(s, t);
        _Qsort(s, i - 1);
        _Qsort(i + 1, t);
    }
}
