#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qrencode-4.1.1/qrencode.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *event);

    void on_pushButton_save_clicked();

private:
    Ui::Widget *ui;
    int _size;//二維碼每格大小
    int _margin;//二維碼與邊界的距離
    QPixmap _centerIcon;
    QByteArray _str;
    QString srcDirPath;

    QPixmap pix;

};
#endif // WIDGET_H
