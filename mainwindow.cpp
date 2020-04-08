#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

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

        insertItem(list, token);

        s.erase(0, pos + delimiter.length());

    }
    insertItem(list, s); // last row

}

void MainWindow::insertItem(QListWidget *list,  std::string row){

    QListWidgetItem* item;
    item = new QListWidgetItem(list);
    list->addItem(item);
    QLabel *label = new QLabel();

    std::string link = "";
    std::string title = "";
    if ( row.find(' ') != std::string::npos ){ // found

        link = "https://en.wikipedia.org" + row.substr(1, row.find(' ') - 2);
        title = row.substr(row.find(' ') + 1);

    }
    else{
        title = row;
    }

    if(link.compare("") == 0){
        label->setText(QString::fromStdString(title));
    }
    else{
        label->setText("<a href=\"" + QString::fromStdString(link) + "\">" + QString::fromStdString(title) + "</a>");
    }

    label->openExternalLinks();
    label->setTextFormat(Qt::RichText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label->setOpenExternalLinks(true);

    list->setItemWidget(item, label);

}
