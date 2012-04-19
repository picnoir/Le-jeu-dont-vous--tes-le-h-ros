#include "CentralWidget.hpp"
#include "TransitionWidget.hpp"
#include "FourChoicesWidget.hpp"
#include "GameOver.hpp"
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
  bool vivant=_mainWindowPtr->getEnginePtr()->applyEffect(number);
  QWidget* old=_gameWidget;
  if(!vivant)
    _gameWidget=new GameOver(this);
  else
    _gameWidget=new TransitionWidget(this,number);
  if(old!=NULL)
    old->deleteLater();
  _layout->addWidget(_gameWidget,0,0);
  _mainWindowPtr->updateHud();
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

void CentralWidget::newGame()
{
  _mainWindowPtr->getEnginePtr()->chooseLevel("01.xml");
  _mainWindowPtr->getEnginePtr()->getPlayerPtr()->setHp(100);
  _mainWindowPtr->getEnginePtr()->getPlayerPtr()->setCp(100);
  createWidget();

}
