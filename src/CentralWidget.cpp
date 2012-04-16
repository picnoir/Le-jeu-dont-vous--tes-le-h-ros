#include "CentralWidget.hpp"
#include "TransitionWidget.hpp"
#include "FourChoicesWidget.hpp"
CentralWidget::CentralWidget(MainWindow* mainWindowPtr):_mainWindowPtr(mainWindowPtr),_gameWidget(NULL)
{
  _hud=new Hud(_mainWindowPtr);
  createWidget();
  _layout=new QGridLayout;
  _layout->addWidget(_gameWidget,0,0);
  _layout->addWidget(_hud,1,0);
  this->setLayout(_layout);
}

CentralWidget::~CentralWidget()
{
  delete _layout;
  delete _hud;
}

void CentralWidget::displayTransitionWidget(int number)
{
  QWidget* old=_gameWidget;
  _gameWidget=new TransitionWidget(this,number);
  if(old!=NULL)
    old->deleteLater();
  _layout->addWidget(_gameWidget,0,0);
  _mainWindowPtr->displayCentral(this);
}


void CentralWidget::nextLevel(int link)
{
  QString linkText=_mainWindowPtr->getEnginePtr()->getLevelPtr()->getLink(link);
  _mainWindowPtr->getEnginePtr()->chooseLevel(linkText.toStdString());
  createWidget();
}


void CentralWidget::createWidget()
{
  _mainWindowPtr->updateHud();
  LevelType type=_mainWindowPtr->getEnginePtr()->getLevelPtr()->getLevelType();
  if(type==FourChoices)
    displayFourChoicesWidget();
}

void CentralWidget::displayFourChoicesWidget()
{
  QWidget* old=_gameWidget;
  _gameWidget=new FourChoicesWidget(this);
  if(old!=NULL)
    {
      old->deleteLater();
      _layout->addWidget(_gameWidget,0,0);
    }
  _mainWindowPtr->displayCentral(this);
}

