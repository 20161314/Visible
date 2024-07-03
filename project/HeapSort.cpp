#include "HeapSort.h"
#include <QThread>
#include <QTimer>

HeapSort::HeapSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void HeapSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &HeapSort::runSort);
    connect(this, &HeapSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void HeapSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        shiftDown(i, n - 1);
    }
    for (int i = n - 1; i > 0; i--) {
        // 交换元素
        int temp = array.get(0);
        array.set(array.get(i), 0);
        array.set(temp, i);

        QThread::msleep(5);
        visual->update();
        shiftDown(0, i - 1);
    }

    QThread::msleep(2000);
    emit finished();
}

void HeapSort::shiftDown(int low, int high)
{
    int i = low;
    int j = 2 * i + 1;
    int temp = array.get(i);
    while (j <= high) {
        if (j < high && array.get(j) < array.get(j + 1)) {
            j++;
        }
        if (temp < array.get(j)) {
            array.set(array.get(j), i);

            QThread::msleep(5);
            visual->update();

            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    array.set(temp, i);
    QThread::msleep(5);
    visual->update();
}
