/**
Widget central: contient le widget de jeu et le HUD
 */

#ifndef CENTRALWIDGET
#define CENTRALWIDGET
#include <QWidget>
#include <QGridLayout>
#include "MainWindow.hpp"
#include "Hud.hpp"
class CentralWidget:public QWidget
{
  Q_OBJECT
protected:
  MainWindow* _mainWindowPtr;
  QWidget* _gameWidget;
  Hud* _hud;
  QGridLayout* _layout;
public slots:
  void displayTransitionWidget(int);
  void nextLevel(int);
  void newGame();
public:
  CentralWidget(MainWindow* mainWindowPtr);
  void displayFourChoicesWidget();
  void createWidget();
  MainWindow* getMainWindowPtr(){return _mainWindowPtr;}
  void setGameWidget(QWidget* widget);
  virtual ~CentralWidget();
};
#endif
