#ifndef MAINWINDOW
#define MAINWINDOW
#include <QMainWindow>
#include <QWidget>
#include <QAction>
#include "Engine.hpp"
class MainWindow: public QMainWindow
{
Q_OBJECT

protected:
  QWidget* _centralWidget;
  QMenu* _menuFichier;
  QAction* _actionQuitter;
  Engine* _enginePtr;
signals:
  void hp(int);
  void cp(int);
public:
  MainWindow(Engine* enginePtr);
  void updateHud();
  void displayCentral(QWidget* widget){setCentralWidget(widget);}
  Engine* getEnginePtr(){return _enginePtr;}
  virtual ~MainWindow();
};

#endif
