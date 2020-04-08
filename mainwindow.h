#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QtDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include <QLabel>
#include <QtCharts/QChartView>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int setDataList(QListWidget *list,  QUrl url, std::string cl);
    void insertItem(QListWidget *list,  std::string row, std::string cl);
    void createCounterGraph(QChartView *graph);
    void createLettersGraph(QChartView *graph, int array[], QString title);
    void countLetter(std::string name, int array[]);
    void initArray(int array[]);

private:
    Ui::MainWindow *ui;
    int emi_counter;
    int universal_counter;
    int emi_letters[26];
    int universal_letters[26];

};
#endif // MAINWINDOW_H
