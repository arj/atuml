#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include "advancedgraphicsscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow ui;

    AdvancedGraphicsScene* scene;

private slots:
	void setMousePosition(const QPointF pos);
};

#endif // MAINWINDOW_H
