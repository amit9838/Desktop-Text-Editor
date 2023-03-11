#include "shortcuts.h"
#include "ui_shortcuts.h"

Shortcuts::Shortcuts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shortcuts)
{
    ui->setupUi(this);
    this->setWindowTitle("Shortcuts");
}

Shortcuts::~Shortcuts()
{
    delete ui;
}
