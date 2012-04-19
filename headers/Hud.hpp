#ifndef HUD
#define HUD
#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "MainWindow.hpp"
class Hud:public QWidget
{
protected:
  QProgressBar* _hpBar;
  QProgressBar* _cpBar;
  MainWindow* _mainWindowPtr;
  QGridLayout* _layout;
  QLabel* _hpText;
  QLabel* _cpText;
public:
  Hud(MainWindow* mainWindowPtr);
  virtual ~Hud();
};

#endif
