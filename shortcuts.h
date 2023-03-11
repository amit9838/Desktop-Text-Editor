#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <QDialog>
namespace Ui {
class Shortcuts;
}

class Shortcuts : public QDialog
{
    Q_OBJECT

public:
    explicit Shortcuts(QWidget *parent = nullptr);
    ~Shortcuts();

private:
    Ui::Shortcuts *ui;
};

#endif // SHORTCUTS_H
