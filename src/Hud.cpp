#include "Hud.hpp"
Hud::Hud(MainWindow* mainWindowPtr):_mainWindowPtr(mainWindowPtr)
{
  _hpBar=new QProgressBar;
  _cpBar=new QProgressBar;
  _hpBar->setValue(80);
  _cpBar->setValue(50);
  _button=new QPushButton("Inventaire");
  _layout=new QGridLayout;
  _hpText=new QLabel("Hp");
  _cpText=new QLabel("Cp");
  _layout->addWidget(_button,0,1);
  _layout->addWidget(_hpText,1,0);
  _layout->addWidget(_hpBar,1,1);
  _layout->addWidget(_cpText,2,0);
  _layout->addWidget(_cpBar,2,1);
  this->setLayout(_layout);
}

Hud::~Hud()
{
  delete _layout;
  delete _button;
  delete _cpBar;
  delete _hpBar;
  delete _hpText;
  delete _cpText;
}
