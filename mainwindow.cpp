#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // Відображення поточних координат миші в заголовку вікна
    QString coordinates = coordinatesToString(event);
    setWindowTitle(coordinates);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Визначаємо, яку кнопку миші натиснув користувач
    QString message;
    if (event->button() == Qt::RightButton)
    {
        message = "Ви натиснули праву кнопку миші.";
    }
    else if (event->button() == Qt::LeftButton)
    {
        message = "Ви натиснули ліву кнопку миші.";
    }
    message += "\n" + coordinatesToString(event);

    // Виведення повідомлення в діалогове вікно
    QString caption = "Клік";
    QMessageBox::information(this, caption, message);
}

QString MainWindow::coordinatesToString(QMouseEvent *event)
{
    QPointF pos = event->position();
    QPoint point = pos.toPoint();
    int x = point.x();
    int y = point.y();
    return QString("Координати миші: x=%1; y=%2").arg(x).arg(y);
}

