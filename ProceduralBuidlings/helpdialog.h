#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include <QDir>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

private:
    Ui::HelpDialog *ui;
    void setColors();
    void setText();
};

#endif // HELPDIALOG_H
