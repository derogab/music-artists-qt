#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QKeyEvent>
#include <iostream>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    // inizializzo la finestra
    ui->setupUi(this);

    // ottengo i dati dalle liste
    setDataList(ui->universal_list, QUrl("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt"));
    setDataList(ui->emi_list, QUrl("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt"));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setDataList(QListWidget *list,  QUrl url){

    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(url));
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString content = response->readAll();

    std::string s = content.toStdString();
    std::string delimiter = "\n";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token << std::endl;

        list->addItem(QString::fromStdString(token));

        s.erase(0, pos + delimiter.length());

    }
    std::cout << s << std::endl;

}
