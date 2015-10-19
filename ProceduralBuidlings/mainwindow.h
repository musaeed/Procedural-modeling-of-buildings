#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QProgressBar>
#include <QFileDialog>
#include <QProcess>
#include <helpdialog.h>
#include <QKeyEvent>
#include <parser.h>
#include <vector>
#include <map>
#include "modeler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setProgress(int value, QString text);
    void openFile();

public slots:

    bool eventFilter(QObject *, QEvent *);

private slots:
    void on_actionOpen_triggered();

    void on_actionFull_screen_triggered();

    void on_actionExit_triggered();

    void on_actionHelp_triggered();

    void on_actionOpen_2_triggered();

    void on_actionFull_screen_2_triggered();

    void on_actionHelp_2_triggered();

private:
    Ui::MainWindow *ui;
    QProgressBar* progress;
    void setCustomStatusBar();
};

#endif // MAINWINDOW_H
