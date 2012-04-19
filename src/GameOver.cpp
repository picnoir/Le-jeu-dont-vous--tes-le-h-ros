#include "GameOver.hpp"

GameOver::GameOver(CentralWidget* ptr):_centralWidgetPtr(ptr)
{
  _button = new QPushButton("Nouvelle partie");
  _text= new QLabel("Vous êtes mort!");
  _text->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  _layout=new QGridLayout;
  _layout->addWidget(_button,1,0);
  _layout->addWidget(_text,0,0);
  this->setLayout(_layout);
  QObject::connect(_button,SIGNAL(clicked()),_centralWidgetPtr,SLOT(newGame()));
}

GameOver::~GameOver()
{
  delete _layout;
  delete _text;
  delete _button;
}
