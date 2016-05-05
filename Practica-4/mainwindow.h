#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <sstream>
#include <QColor>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void printOnScreen();
    void statusOperationButtons(bool status);

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_mas_clicked();

    void on_pushButton_menos_clicked();

    void on_pushButton_por_clicked();

    void on_pushButton_entre_clicked();

    void on_pushButton_igual_clicked();

    void on_pushButton_igual_2_clicked();

    void on_pushButton_coma_clicked();

    void on_pushButton_dot_clicked();

private:
    Ui::MainWindow *ui;
    std::stringstream strstm;
};

#endif // MAINWINDOW_H
