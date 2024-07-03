#include "InsertSort.h"
#include <QThread>
#include <QTimer>

InsertSort::InsertSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void InsertSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &InsertSort::runSort);
    connect(this, &InsertSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void InsertSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    for (int i = 1; i < n; i++) {
        int key = array.get(i);
        int j = i - 1;
        while (j >= 0 && array.get(j) > key) {
            array.set(array.get(j), j + 1);
            j--;
            QThread::msleep(5);
            visual->update();
        }
        array.set(key, j + 1);

        QThread::msleep(5);
        visual->update();
    }

    QThread::msleep(2000);
    emit finished();
}
