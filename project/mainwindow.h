#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arraytosort.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    ArrayToSort& getArray();

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void DoInsertSort();
    void DoBinarySort();
    void DoShellSort();
    void DoBubbleSort();
    void DoQuickSort();
    void DoSelectionSort();
    void DoHeapSort();
    void DoMergeSort();
    void DoRadixSort(int r = 10);

private slots:
    void on_SetSizeButton_clicked();

    void on_ButtonShuffle_clicked();

    void on_SetDelayButton_clicked();

    void on_Button1_Insert_clicked();

    void on_Button2_Binary_clicked();

    void on_Button3_Shell_clicked();

    void on_Button4_Bubble_clicked();

    void on_Button5_Quick_clicked();

    void on_Button6_Selection_clicked();

    void on_Button7_Heap_clicked();

    void on_Button8_Merge_clicked();

    void on_Button9_Radix_clicked();

private:
    Ui::MainWindow *ui;

    ArrayToSort array;

    int delay = 5;

    void Paint();
};
#endif // MAINWINDOW_H
