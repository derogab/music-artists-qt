#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    // inizializzo la finestra
    ui->setupUi(this);

    // init counters
    initArray(universal_letters);
    initArray(emi_letters);

    // ottengo i dati dalle liste
    universal_counter = setDataList(ui->universal_list, QUrl("https://raw.githubusercontent.com/derogab/music-artists-qt/master/.dataset/List_of_Universal_artists.txt"), "UNIVERSAL");
    emi_counter =setDataList(ui->emi_list, QUrl("https://raw.githubusercontent.com/derogab/music-artists-qt/master/.dataset/List_of_EMI_artists.txt"), "EMI");

    // creo il grafico con conteggio dei nomi
    if(universal_counter != 0 || emi_counter != 0)
        createCounterGraph(ui->counter_graph);
    else
        ui->error_label->setText("Nessun dato scaricato");

    // creo i grafici per le lettere
    if(universal_counter != 0)
        createLettersGraph(ui->universal_letters_graph, universal_letters, "Artisti della Universal divisi per lettera");
    if(emi_counter != 0)
        createLettersGraph(ui->emi_letters_graph, emi_letters, "Artisti della EMI divisi per lettera");

}

MainWindow::~MainWindow() {
    delete ui;

}

void MainWindow::createCounterGraph(QChartView *graph){

    QPieSeries *series = new QPieSeries();
    series->append("UNIVERSAL", universal_counter);
    series->append("EMI", emi_counter);

    for(auto slice : series->slices()){
        slice->setLabelBrush(QBrush(Qt::white));
        slice->setLabel(slice->label() + ": "  + QString::number(slice->value()));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Artisti per Etichetta");

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->legend()->color();

    graph->setChart(chart);
    graph->setRenderHint(QPainter::Antialiasing);





}

void MainWindow::createLettersGraph(QChartView *graph, int array[], QString title = ""){

    QBarSet *set0 = new QBarSet("A");
    QBarSet *set1 = new QBarSet("B");
    QBarSet *set2 = new QBarSet("C");
    QBarSet *set3 = new QBarSet("D");
    QBarSet *set4 = new QBarSet("E");
    QBarSet *set5 = new QBarSet("F");
    QBarSet *set6 = new QBarSet("G");
    QBarSet *set7 = new QBarSet("H");
    QBarSet *set8 = new QBarSet("I");
    QBarSet *set9 = new QBarSet("J");
    QBarSet *set10 = new QBarSet("K");
    QBarSet *set11 = new QBarSet("L");
    QBarSet *set12 = new QBarSet("M");
    QBarSet *set13 = new QBarSet("N");
    QBarSet *set14 = new QBarSet("O");
    QBarSet *set15 = new QBarSet("P");
    QBarSet *set16 = new QBarSet("Q");
    QBarSet *set17 = new QBarSet("R");
    QBarSet *set18 = new QBarSet("S");
    QBarSet *set19 = new QBarSet("T");
    QBarSet *set20 = new QBarSet("U");
    QBarSet *set21 = new QBarSet("V");
    QBarSet *set22 = new QBarSet("W");
    QBarSet *set23 = new QBarSet("X");
    QBarSet *set24 = new QBarSet("Y");
    QBarSet *set25 = new QBarSet("Z");

    *set0 << array[0];
    *set1 << array[1];
    *set2 << array[2];
    *set3 << array[3];
    *set4 << array[4];
    *set5 << array[5];
    *set6 << array[6];
    *set7 << array[7];
    *set8 << array[8];
    *set9 << array[9];
    *set10 << array[10];
    *set11 << array[11];
    *set12 << array[12];
    *set13 << array[13];
    *set14 << array[14];
    *set15 << array[15];
    *set16 << array[16];
    *set17 << array[17];
    *set18 << array[18];
    *set19 << array[19];
    *set20 << array[20];
    *set21 << array[21];
    *set22 << array[22];
    *set23 << array[23];
    *set24 << array[24];
    *set25 << array[25];

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);
    series->append(set7);
    series->append(set8);
    series->append(set9);
    series->append(set10);
    series->append(set11);
    series->append(set12);
    series->append(set13);
    series->append(set14);
    series->append(set15);
    series->append(set16);
    series->append(set17);
    series->append(set18);
    series->append(set19);
    series->append(set20);
    series->append(set21);
    series->append(set22);
    series->append(set23);
    series->append(set24);
    series->append(set25);

    series->setLabelsVisible();
    series->setBarWidth(1);
    series->setLabelsAngle(270);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Contatore");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->layout()->setContentsMargins(2, 2, 2, 2);
    chart->setMargins(QMargins(2, 2, 2, 2));

    graph->setChart(chart);
    graph->setRenderHint(QPainter::Antialiasing);

}

void MainWindow::initArray(int array[]){
    for (int i = 0; i < 26; i++) {
        array[i] = 0;
    }
}

void MainWindow::countLetter(std::string name, int array[]){

    switch(name[0]){
        case 'a':
        case 'A': array[0]++; break;
        case 'b':
        case 'B': array[1]++; break;
        case 'c':
        case 'C': array[2]++; break;
        case 'd':
        case 'D': array[3]++; break;
        case 'e':
        case 'E': array[4]++; break;
        case 'f':
        case 'F': array[5]++; break;
        case 'g':
        case 'G': array[6]++; break;
        case 'h':
        case 'H': array[7]++; break;
        case 'i':
        case 'I': array[8]++; break;
        case 'j':
        case 'J': array[9]++; break;
        case 'k':
        case 'K': array[10]++; break;
        case 'l':
        case 'L': array[11]++; break;
        case 'm':
        case 'M': array[12]++; break;
        case 'n':
        case 'N': array[13]++; break;
        case 'o':
        case 'O': array[14]++; break;
        case 'p':
        case 'P': array[15]++; break;
        case 'q':
        case 'Q': array[16]++; break;
        case 'r':
        case 'R': array[17]++; break;
        case 's':
        case 'S': array[18]++; break;
        case 't':
        case 'T': array[19]++; break;
        case 'u':
        case 'U': array[20]++; break;
        case 'v':
        case 'V': array[21]++; break;
        case 'w':
        case 'W': array[22]++; break;
        case 'x':
        case 'X': array[23]++; break;
        case 'y':
        case 'Y': array[24]++; break;
        case 'z':
        case 'Z': array[25]++; break;

    }

}

int MainWindow::setDataList(QListWidget *list,  QUrl url, std::string cl = ""){

    QNetworkAccessManager manager;

    QNetworkReply *response;
    try {
        response = manager.get(QNetworkRequest(url));
    } catch (...) {
        ui->error_label->setText("Errore di rete");
    }

    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));

    try {
        event.exec();
    } catch (...) {
        ui->error_label->setText("Errore di rete");
    }

    QString content = response->readAll();

    std::string s = content.toStdString();
    std::string delimiter = "\n";

    int counter = 0;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);

        insertItem(list, token, cl);
        counter++;

        s.erase(0, pos + delimiter.length());

    }
    insertItem(list, s, cl); // last row
    counter++;

    return counter;

}

void MainWindow::insertItem(QListWidget *list, std::string row, std::string cl = ""){

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

    if(cl.compare("EMI") == 0)
       countLetter(title, emi_letters);
    else if(cl.compare("UNIVERSAL") == 0)
       countLetter(title, universal_letters);

}
