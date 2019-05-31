#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digito_oprimido();
    void on_pushButton_clear_released();
    void on_pushButton_decimal_released();
    void operaciones();
    void on_pushButton_equal_released();
};

#endif // MAINWINDOW_H
