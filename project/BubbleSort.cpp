#include "BubbleSort.h"
#include <QThread>
#include <QTimer>

BubbleSort::BubbleSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void BubbleSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &BubbleSort::runSort);
    connect(this, &BubbleSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void BubbleSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    for (int i = 0; i < n - 1; i++) {
        bool exchange = false;
        for (int j = n - 1; j > i; j--) {
            if (array.get(j) < array.get(j - 1)) {
                // 交换元素
                int temp = array.get(j);
                array.set(array.get(j - 1), j);
                array.set(temp, j - 1);
                exchange = true;
            }
            QThread::msleep(5);
            visual->update();
        }
        if (!exchange) break;
    }

    QThread::msleep(2000);
    emit finished();
}
