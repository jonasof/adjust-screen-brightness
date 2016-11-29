#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <sstream>
//#include "X11/extensions/Xrandr.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    float brightness = value / 100.0;

    std::ostringstream ss;
    ss << "xrandr --output LVDS1 --brightness " << brightness;

    system(ss.str().c_str());
}

void updateGamma(float r, float g, float b)
{

    float gammaR = r / 100.0;
    float gammaG = g / 100.0;
    float gammaB = b / 100.0;

    std::ostringstream ss;
    ss << "xrandr --output LVDS1 --gamma " << gammaR << ":" << gammaG << ":" << gammaB;

    system(ss.str().c_str());

}

void MainWindow::on_gammaRSlider_valueChanged(int value)
{
    updateGamma(ui->gammaRSlider->value(), ui->gammaGSlider->value(), ui->gammaBSlider->value() );
}

void MainWindow::on_gammaGSlider_valueChanged(int value)
{
    updateGamma(ui->gammaRSlider->value(), ui->gammaGSlider->value(), ui->gammaBSlider->value() );
}

void MainWindow::on_gammaBSlider_valueChanged(int value)
{
    updateGamma(ui->gammaRSlider->value(), ui->gammaGSlider->value(), ui->gammaBSlider->value() );
}

void MainWindow::on_lightSlider_valueChanged(int value)
{
    std::ostringstream ss;
    ss << "xbacklight -set " << value;

    system(ss.str().c_str());
}
