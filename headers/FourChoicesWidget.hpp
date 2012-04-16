#ifndef FOURCHOICESWIDGET
#define FOURCHOICESWIDGET
#include <QLabel>
#include <QList>
#include <QString>
#include <QGridLayout>
#include <QSignalMapper>
#include <QPushButton>
#include "MainWindow.hpp"
class FourChoicesWidget: public QWidget
{
protected:
  QLabel* _textZone;
  QList<QPushButton*> _buttons;
  QGridLayout* _layout;
  MainWindow* _mainWindowPtr;
  QSignalMapper* _signalMapper;
public:
  FourChoicesWidget(MainWindow* mainWindowPtr);
  virtual ~FourChoicesWidget();
};

#endif
