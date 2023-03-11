#include "aboutdev.h"
#include "ui_aboutdev.h"
#include<QDesktopServices>
#include<QUrl>

aboutDev::aboutDev(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDev)
{
    ui->setupUi(this);
    this->setWindowTitle("About Developer");
}

aboutDev::~aboutDev()
{
    delete ui;
}


void aboutDev::on_github_link_clicked()
{
    QString  link = "https://github.com/amit9838";
    QDesktopServices::openUrl(QUrl(link));
}


void aboutDev::on_resume_link_clicked()
{
    QString  link = "https://drive.google.com/drive/folders/1mwcews0Fvj_UnCS3Wc9ax-0KLYrtFlHY?usp=share_link";
    QDesktopServices::openUrl(QUrl(link));
}

