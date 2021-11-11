#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QBrush>
#include <QPixmap>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->_centerIcon = QPixmap(":/new/circus-tent.png");
    this->setWindowTitle("二維碼產生器");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString tmp = ui->lineEdit->text();
    if(tmp.isEmpty())
    {
        tmp = "你忘了輸入資料了";
    }
    _str = tmp.toUtf8();
    update();
    qDebug() << tmp << _str << Qt::endl;


}

void Widget::paintEvent(QPaintEvent *event)
{
    pix = QPixmap(400,400);
    pix.fill(Qt::white);
    QPainter p(&pix);

    QPainter painter(this);
    QBrush brush(Qt::black);
    painter.setBrush(brush);
    p.setBrush(brush);
    //version 二維碼版本
    //level 容錯等級
    //Mode : utf8
    //casesensitive (true or false)

    QRcode* newqrcode = QRcode_encodeString(_str.data(), 7, QR_ECLEVEL_Q, QR_MODE_8, true);

    if(newqrcode!=NULL)
    {
        //newqrcode->width 行數 算比例 _size就是格子的大小
        this->_size = (this->width() - 130) / newqrcode -> width;
        this->_margin = (this->width()/ 2) - (newqrcode->width * _size) / 2;
        unsigned char* poin = newqrcode -> data;
        for(int i = 0; i < newqrcode->width; i ++)
        {
            for(int j = 0; j < newqrcode -> width; j++)
            {
                if(*poin & 1)
                {
                    QRectF r(i * _size + _margin, j *_size + _margin + 40, _size, _size);
                    QRectF r2(i * _size + _margin, j *_size + _margin , _size, _size);

                    painter.drawRect(r);
                    p.drawRect(r2);
                }
                poin ++;
            }
        }
        double scale = 0.23;
        double icon_size = (this->width() - 2.0 * _margin) * scale;
        double ix = this -> width() / 2.0 - icon_size / 2.0;
        double iy = this -> height() / 2.0 - icon_size / 2.0;
        QRect icon(ix,iy,icon_size,icon_size);
        QRect icon2(ix,iy - 30,icon_size,icon_size);

        painter.drawPixmap(icon,_centerIcon);
        p.drawPixmap(icon2, _centerIcon);

        p.end();

    }
}

void Widget::on_pushButton_save_clicked()
{
    QString filename = ui->lineEdit_2->text();
        srcDirPath = QFileDialog::getExistingDirectory(
                   this, "choose src Directory",
                    "/");

        if (srcDirPath.isEmpty())
        {
            return;
        }
        else
        {
            qDebug() << "srcDirPath=" << srcDirPath;
            srcDirPath += "/";
        }
        if(filename.isEmpty())
            pix.save(srcDirPath + "default.png");
        else
            pix.save(srcDirPath + filename.toUtf8() + ".png");
        update();
}
