#include "SelectionSort.h"
#include <QThread>
#include <QTimer>

SelectionSort::SelectionSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void SelectionSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &SelectionSort::runSort);
    connect(this, &SelectionSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void SelectionSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (array.get(j) < array.get(minj))
                minj = j;
        }
        if (minj != i)
            swap(i, minj);

        QThread::msleep(5);
        visual->update();
    }

    QThread::msleep(2000);
    emit finished();
}

void SelectionSort::swap(int i, int j)
{
    int temp = array.get(i);
    array.set(array.get(j), i);
    array.set(temp, j);
}
