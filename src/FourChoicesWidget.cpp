#include "FourChoicesWidget.hpp"
FourChoicesWidget::FourChoicesWidget(CentralWidget* parentPtr):_parentPtr(parentPtr)
{
  int i;
  QList<QString> buttonText;
  buttonText=_parentPtr->getMainWindowPtr()->getEnginePtr()->getLevelPtr()->getButtonsName();


  _signalMapper= new QSignalMapper(this);
  _textZone=new QLabel;
  _textZone->setText(_parentPtr->getMainWindowPtr()->getEnginePtr()->getLevelPtr()->getText());
  _textZone->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  _layout=new QGridLayout;
  for(i=0;i<4;++i)
    {
      _buttons.append(new QPushButton(buttonText[i]));
      QObject::connect(_buttons[i], SIGNAL(clicked()), _signalMapper, SLOT(map()));
      _signalMapper->setMapping(_buttons[i], i);
    }
  QObject::connect(_signalMapper,SIGNAL(mapped(int)),_parentPtr,SLOT(displayTransitionWidget(int)));
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
  delete _textZone;
  delete _layout;
  delete _signalMapper;
}
