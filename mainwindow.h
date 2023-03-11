#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include<QDebug>
#include <QTextEdit>
#include <QMainWindow>
#include <QStatusBar>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
 #include <QTextCursor>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprintdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedu_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionunderline_triggered();

    void on_actionReset_Formatting_triggered();

    void on_actionSuperscript_triggered();

    void on_actionSubscript_triggered();

    void on_actionShortcuts_triggered();

    void on_actionAbout_Text_Editor_triggered();

    void on_actionAbout_Developer_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
