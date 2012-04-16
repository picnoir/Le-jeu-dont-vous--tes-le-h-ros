#ifndef FOURCHOICESWIDGET
#define FOURCHOICESWIDGET
#include <QLabel>
#include <QList>
#include <QString>
#include <QGridLayout>
#include <QSignalMapper>
#include <QPushButton>
#include "CentralWidget.hpp"
class FourChoicesWidget: public QWidget
{
protected:
  QLabel* _textZone;
  QList<QPushButton*> _buttons;
  QGridLayout* _layout;
  CentralWidget* _parentPtr;
  QSignalMapper* _signalMapper;
public:
  FourChoicesWidget(CentralWidget* parentPtr);
  virtual ~FourChoicesWidget();
};

#endif
