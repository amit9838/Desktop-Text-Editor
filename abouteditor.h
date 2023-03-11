#ifndef ABOUTEDITOR_H
#define ABOUTEDITOR_H

#include <QDialog>

namespace Ui {
class AboutEditor;
}

class AboutEditor : public QDialog
{
    Q_OBJECT

public:
    explicit AboutEditor(QWidget *parent = nullptr);
    ~AboutEditor();

private:
    Ui::AboutEditor *ui;
};

#endif // ABOUTEDITOR_H
