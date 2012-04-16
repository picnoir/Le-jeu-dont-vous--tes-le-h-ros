#include "TransitionWidget.hpp"
TransitionWidget::TransitionWidget(MainWindow* mainWindowPtr, int number):_mainWindowPtr(mainWindowPtr)
{
  QString text=_mainWindowPtr->getEnginePtr()->getLevelPtr()->getEffectText(number);
  _textZone=new QLabel(text);
  _textZone->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  _mapper=new QSignalMapper(this);
  _button=new QPushButton("Ok");
  _mapper->setMapping(_button,number);
  _layout=new QVBoxLayout;
  _layout->addWidget(_textZone);
  _layout->addWidget(_button);
  this->setLayout(_layout);
  QObject::connect(_button, SIGNAL(clicked()), _mapper, SLOT(map()));
  QObject::connect(_mapper,SIGNAL(mapped(int)),_mainWindowPtr,SLOT(nextLevel(int)));
}

TransitionWidget::~TransitionWidget()
{
  QObject::disconnect(_mapper,SIGNAL(mapped(int)),_mainWindowPtr,SLOT(nextLevel(int)));
  QObject::disconnect(_button,SIGNAL(clicked()),_mapper,SLOT(map()));
  delete _textZone;
  delete _mapper;
  delete _button;
  delete _layout;
}
