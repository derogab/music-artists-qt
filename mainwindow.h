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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setDataList(QListWidget *list,  QUrl url);
    void insertItem(QListWidget *list,  std::string row);

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
