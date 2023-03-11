#include "abouteditor.h"
#include "ui_abouteditor.h"

AboutEditor::AboutEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutEditor)
{
    ui->setupUi(this);
    this->setWindowTitle("About Text Editor");

}

AboutEditor::~AboutEditor()
{
    delete ui;
}
