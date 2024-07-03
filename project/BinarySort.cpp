#include "BinarySort.h"
#include <QThread>
#include <QTimer>

BinarySort::BinarySort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void BinarySort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &BinarySort::runSort);
    connect(this, &BinarySort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void BinarySort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    for (int i = 1; i < n; i++) {
        if (array.get(i) < array.get(i - 1)) {
            int temp = array.get(i);
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (temp < array.get(mid))
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= high + 1; j--) {
                array.set(array.get(j), j + 1);

                QThread::msleep(5);
                visual->update();
            }
            array.set(temp, high + 1);
        }

        QThread::msleep(5);
        visual->update();
    }

    QThread::msleep(2000);
    emit finished();
}
