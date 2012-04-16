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
  QWidget* _old;
public slots:
  void displayTransitionWidget(int);
  void nextLevel(int);
public:
  MainWindow(Engine* enginePtr);
  void createWidget();
  Engine* getEnginePtr(){return _enginePtr;}
  void displayFourChoicesWidget();
  virtual ~MainWindow();
};

#endif
