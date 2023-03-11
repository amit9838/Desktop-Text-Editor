#ifndef ABOUTDEV_H
#define ABOUTDEV_H

#include <QDialog>

namespace Ui {
class aboutDev;
}

class aboutDev : public QDialog
{
    Q_OBJECT

public:
    explicit aboutDev(QWidget *parent = nullptr);
    ~aboutDev();

private slots:
    void on_github_link_clicked();

    void on_resume_link_clicked();

private:
    Ui::aboutDev *ui;
};

#endif // ABOUTDEV_H
