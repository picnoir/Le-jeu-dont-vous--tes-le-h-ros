#ifndef MAINWINDOW
#define MAINWINDOW
#include <QMainWindow>
#include <QWidget>
#include <QAction>
#include "Engine.hpp"
class MainWindow: public QMainWindow
{
protected:
  QWidget* _centralWidget;
  QMenu* _menuFichier;
  QAction* _actionQuitter;
  Engine* _enginePtr;
public:
  MainWindow(Engine* enginePtr);
  void displayCentral(QWidget* widget){setCentralWidget(widget);}
  Engine* getEnginePtr(){return _enginePtr;}
  virtual ~MainWindow();
};

#endif
