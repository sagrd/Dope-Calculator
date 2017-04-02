#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_zero_clicked();
    void on_one_clicked();
    void on_two_clicked();
    void on_three_clicked();
    void on_four_clicked();
    void on_five_clicked();
    void on_six_clicked();
    void on_seven_clicked();
    void on_eight_clicked();
    void on_nine_clicked();

    void on_decimal_clicked();

    void on_clearButton_clicked();

    void on_operation_actionTriggered(int action);

    void on_operation_sliderMoved(int position);

    void on_equals_clicked();

    void on_square_clicked();

    void on_sign_clicked();

    void on_backspace_clicked();

    void on_copyright_clicked();

    void on_squareRoot_clicked();

    void on_percentage_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
