#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void print();
    Ui::MainWindow * getUi();
    ~MainWindow();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
