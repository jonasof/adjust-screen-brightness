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
    void on_brightnessSlider_valueChanged(int value);

    void on_gammaSlider_valueChanged(int value);

    void on_gammaRSlider_valueChanged(int value);

    void on_gammaGSlider_valueChanged(int value);

    void on_gammaBSlider_valueChanged(int value);

    void on_lightSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
