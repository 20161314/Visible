#include "MergeSort.h"
#include <QThread>
#include <QTimer>
#include <vector>

MergeSort::MergeSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void MergeSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &MergeSort::runSort);
    connect(this, &MergeSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void MergeSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    _Msort(0, n - 1);

    QThread::msleep(2000);
    emit finished();
}

void MergeSort::Merge(int low, int mid, int high)
{
    std::vector<int> R1(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (array.get(i) <= array.get(j)) {
            R1[k] = array.get(i);
            i++; k++;
        }
        else {
            R1[k] = array.get(j);
            j++; k++;
        }
    }
    while (i <= mid) {
        R1[k] = array.get(i);
        i++; k++;
    }
    while (j <= high) {
        R1[k] = array.get(j);
        j++; k++;
    }
    for (k = 0, i = low; i <= high; k++, i++) {
        array.set(R1[k], i);

        QThread::msleep(5);
        visual->update();
    }
}

void MergeSort::_Msort(int s, int t)
{
    if (s >= t) return;
    int m = (s + t) / 2;
    _Msort(s, m);
    _Msort(m + 1, t);
    Merge(s, m, t);
}
