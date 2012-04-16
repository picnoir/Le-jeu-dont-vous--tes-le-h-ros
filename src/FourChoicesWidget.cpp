#include "FourChoicesWidget.hpp"
FourChoicesWidget::FourChoicesWidget(MainWindow* mainWindowPtr):_mainWindowPtr(mainWindowPtr)
{
  int i;
  QList<QString> buttonText;
  buttonText=_mainWindowPtr->getEnginePtr()->getLevelPtr()->getButtonsName();


  _signalMapper= new QSignalMapper(this);
  _textZone=new QLabel;
  _textZone->setText(_mainWindowPtr->getEnginePtr()->getLevelPtr()->getText());
  _textZone->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  _layout=new QGridLayout;
  for(i=0;i<4;++i)
    {
      _buttons.append(new QPushButton(buttonText[i]));
      QObject::connect(_buttons[i], SIGNAL(clicked()), _signalMapper, SLOT(map()));
      _signalMapper->setMapping(_buttons[i], i);
    }
  QObject::connect(_signalMapper,SIGNAL(mapped(int)),_mainWindowPtr,SLOT(displayTransitionWidget(int)));
  _layout->addWidget(_textZone,0,0,1,2);
  _layout->addWidget(_buttons[0],1,0);
  _layout->addWidget(_buttons[1],1,1);
  _layout->addWidget(_buttons[2],2,0);
  _layout->addWidget(_buttons[3],2,1);
  this->setLayout(_layout);
}

FourChoicesWidget::~FourChoicesWidget()
{
  int i;
  for(i=0;i<4;++i)
    {
      QObject::disconnect(_buttons[i], SIGNAL(clicked()),_signalMapper,SLOT(map()));
      delete _buttons[i];
    }
  QObject::disconnect(_signalMapper,SIGNAL(mapped(int)),_mainWindowPtr,SLOT(displayTransitionWidget(int)));
  delete _textZone;
  delete _layout;
  delete _signalMapper;
}
