#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCustomStatusBar();
    installEventFilter(this);

    ui->actionOpen_2->setShortcut(Qt::Key_O | Qt::CTRL);
    ui->actionFull_screen_2->setShortcut(Qt::Key_F11);
    ui->actionHelp_2->setShortcut(Qt::Key_F1);

    ui->actionOpen->setShortcut(Qt::Key_O | Qt::CTRL);
    ui->actionFull_screen->setShortcut(Qt::Key_F11);
    ui->actionHelp->setShortcut(Qt::Key_F1);
}

MainWindow::~MainWindow()
{
    delete progress;
    delete ui;
}


void MainWindow::setCustomStatusBar(){

    ui->statusBar->showMessage("Ready");

    this->progress = new QProgressBar();
    progress->setTextVisible(true);
    ui->statusBar->addPermanentWidget(progress);

}

bool MainWindow::eventFilter(QObject *o, QEvent *e)
{
    if(e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent *>(e);
        if (ke->key() == Qt::Key_Escape){

            ui->mainToolBar->show();
            ui->statusBar->show();
            this->showMaximized();
        }
    }
        return false;
    }

    void MainWindow::setProgress(int value, QString text){

        progress->setValue(value);
        progress->setFormat(text);
    }

    void MainWindow::on_actionOpen_triggered()
    {
        openFile();
    }

    void MainWindow::on_actionFull_screen_triggered()
    {
        system("notify-send 'Procedural modelling of buildings' 'Please use escape to exit fullscreen'");
        this->showFullScreen();
        ui->mainToolBar->hide();
        ui->statusBar->hide();

    }

    void MainWindow::on_actionExit_triggered()
    {
        QCoreApplication::quit();
    }

    void MainWindow::on_actionHelp_triggered()
    {
        HelpDialog dialog(this);
        dialog.show();
        dialog.exec();
    }

    void MainWindow::on_actionOpen_2_triggered()
    {
        openFile();
    }

    void MainWindow::openFile(){

        //QString name = QFileDialog::getOpenFileName(this, "Select grammer file","",tr("Files (* txt)"));

/*        if(name.isEmpty()){

            return;
        }*/

        QString name = "/home/muhammad/Desktop/modeler/grammar.txt";

        Parser parser(name);
        map<int, Rules> result = parser.extract_rules();
        Modeler modeler;
        modeler.Model(result);
        cout << modeler.queue[2]->childs.size() << endl;
        //ui->GLRenderer->openNewGrammar(modeler.queue[1]);

    }

    void MainWindow::on_actionFull_screen_2_triggered()
    {
        system("notify-send 'Procedural modelling of buildings' 'Please use escape to exit fullscreen'");
        this->showFullScreen();
        ui->mainToolBar->hide();
        ui->statusBar->hide();
    }

    void MainWindow::on_actionHelp_2_triggered()
    {
        HelpDialog dialog(this);
        dialog.show();
        dialog.exec();
    }
