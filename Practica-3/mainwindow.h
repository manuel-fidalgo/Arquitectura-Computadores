#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix_test.h"
#include "image_test.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *getUi();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Ok_1_clicked();
    void on_Ok_2_clicked();

private:
    Ui::MainWindow *ui;
    Matrix_test matrix_test;
    Image_test image_test;

};

#endif // MAINWINDOW_H
