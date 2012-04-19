#ifndef GAMEOVER
#define GAMEOVER
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "CentralWidget.hpp"
class GameOver:public QWidget
{
protected:
  QPushButton* _button;
  QLabel* _text;
  QGridLayout* _layout;
  CentralWidget* _centralWidgetPtr;
public:
  GameOver(CentralWidget* ptr);
  ~GameOver();
};
#endif
