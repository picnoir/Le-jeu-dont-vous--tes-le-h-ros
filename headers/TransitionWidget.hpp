#ifndef TRANSITIONWIDGET
#define TRANSITIONWIDGET
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSignalMapper>
#include "MainWindow.hpp"
class TransitionWidget:public QWidget
{
protected:
  QLabel* _textZone;
  QPushButton* _button;
  QVBoxLayout *_layout;
  QSignalMapper* _mapper;
  MainWindow* _mainWindowPtr;
public:
  TransitionWidget(MainWindow* mainWindowPtr, int number);
  virtual ~TransitionWidget();
};

#endif
