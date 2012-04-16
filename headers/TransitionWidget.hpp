#ifndef TRANSITIONWIDGET
#define TRANSITIONWIDGET
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSignalMapper>
#include "CentralWidget.hpp"
class TransitionWidget:public QWidget
{
protected:
  QLabel* _textZone;
  QPushButton* _button;
  QVBoxLayout *_layout;
  QSignalMapper* _mapper;
  CentralWidget* _parentPtr;
public:
  TransitionWidget(CentralWidget* parent, int number);
  virtual ~TransitionWidget();
};

#endif
