#include "ShellSort.h"
#include <QThread>
#include <QTimer>

ShellSort::ShellSort(MainWindow *visual) : visual(visual), array(visual->getArray())
{
}

void ShellSort::startSort()
{
    QThread *thread = new QThread;
    this->moveToThread(thread);

    connect(thread, &QThread::started, this, &ShellSort::runSort);
    connect(this, &ShellSort::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

void ShellSort::runSort()
{
    QThread::msleep(500);

    int n = array.n;
    int d = n / 2;
    while (d > 0) {
        for (int i = d; i < n; i++) {
            if (array.get(i) < array.get(i - d)) {
                int temp = array.get(i);
                int j = i - d;
                do {
                    array.set(array.get(j), j + d);
                    j -= d;

                    QThread::msleep(5);
                    visual->update();

                } while (j >= 0 && array.get(j) > temp);
                array.set(temp, j + d);
            }
            QThread::msleep(5);
            visual->update();
        }
        d = d / 2;
    }

    QThread::msleep(2000);
    emit finished();
}
