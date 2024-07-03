#include "RadixSort.h"
#include <QThread>
#include <QTimer>
#include <queue>
#include <vector>

RadixSort::RadixSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void RadixSort::startSort(int r)
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, [this, r]() { runSort(r); });
    connect(this, &RadixSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void RadixSort::runSort(int r)
{
    QThread::msleep(500);

    int n = array.n;
    int d = this->getd(r);

    std::vector<std::queue<int>> ques(r);
    for (int i = 0; i < d; i++) {
        // distribute
        for (int j = 0; j < n; j++) {
            int k = this->geti(array.get(j), r, i);
            ques[k].push(array.get(j));
        }

        // recollect
        int pos = 0;
        for (int j = 0; j < r; j++) {
            while (!ques[j].empty()) {
                array.set(ques[j].front(), pos);
                pos++;
                ques[j].pop();

                QThread::msleep(5);
                visual->update();
            }
        }
    }

    QThread::msleep(2000);
    emit finished();
}

int RadixSort::getd(int r)
{
    int n = array.n, ma = array.get(0);
    for (int i = 1; i < n; i++) {
        if (array.get(i) > ma)
            ma = array.get(i);
    }

    int times = 1;
    while (ma > 0) {
        ma /= r;
        times++;
    }
    return times;
}

int RadixSort::geti(int key, int r, int i)
{
    int k = 0;
    for (int j = 0; j <= i; j++) {
        k = key % r;
        key = key / r;
    }
    return k;
}
