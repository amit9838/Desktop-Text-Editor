#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./shortcuts.h"
#include "./abouteditor.h"
#include "aboutdev.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Text Editor");
    ui->toolBar->setIconSize(QSize(20,16));
    this->setCentralWidget(ui->textEdit);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNew_triggered()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation!", "Are you sure want to create new document?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      qDebug() << "Yes was clicked";
      currentFile.clear();
      ui->textEdit->setMarkdown(QString());
    } else {
      qDebug() << "Yes was *not* clicked";
    }


}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file :" + file.errorString());
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setMarkdown(text);
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file :" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toMarkdown();
    out<<text;
    file.close();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedu_triggered()
{
    ui->textEdit->redo();
}





void MainWindow::on_actionBold_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfWord);
    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
    QTextCharFormat format;
    format.setFontWeight(800);
    cursor.setCharFormat(format);
    cursor.clearSelection();
    statusBar()->showMessage("Bold text enabled!",2000);
    qDebug("Bold text enabled");
}


void MainWindow::on_actionItalic_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfWord);
    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);

    QTextCharFormat format;
    format.setFontItalic(true);
//    format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    cursor.setCharFormat(format);
    cursor.clearSelection();
    statusBar()->showMessage("Italics text enabled!",2000);
    qDebug("Italics text enabled");
}


void MainWindow::on_actionunderline_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfWord);
    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);

    QTextCharFormat format;
    format.setUnderlineStyle(QTextCharFormat::SingleUnderline);
    cursor.setCharFormat(format);
    cursor.clearSelection();
    statusBar()->showMessage("Underline text enabled!",2000);
    qDebug("Underline text enabled");
}


void MainWindow::on_actionReset_Formatting_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::NoMove);
    QTextCharFormat format;
    format.setFontWeight(400);
    cursor.setCharFormat(format);
    cursor.clearSelection();
    statusBar()->showMessage("Text formatting has been reset!",2000);
    qDebug("Text formatting has been reset.");

}

void MainWindow::on_actionSuperscript_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfWord);
    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);

    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    cursor.setCharFormat(format);
    cursor.clearSelection();
    statusBar()->showMessage("Superscript text enabled!",2000);
    qDebug("Superscript text enabled");
}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfWord);
    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);

    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    cursor.setCharFormat(format);
    cursor.clearSelection();
    statusBar()->showMessage("Subscript text enabled!",2000);
    qDebug("Subscript text enabled");
}


void MainWindow::on_actionShortcuts_triggered()
{
    Shortcuts shortcutsWin;
    shortcutsWin.show();
    shortcutsWin.exec();
}


void MainWindow::on_actionAbout_Text_Editor_triggered()
{
    AboutEditor win;
    win.show();
    win.exec();
}


void MainWindow::on_actionAbout_Developer_triggered()
{
    aboutDev win;
    win.show();
    win.exec();
}

