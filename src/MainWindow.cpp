#include "MainWindow.hpp"
#include "TransitionWidget.hpp"
#include "FourChoicesWidget.hpp"
#include <QtGui>
MainWindow::MainWindow(Engine* enginePtr):_centralWidget(NULL),_enginePtr(enginePtr)
{
  _menuFichier=menuBar()->addMenu("&Fichier");
  _actionQuitter=new QAction("&Quitter",this);
  _actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
  _menuFichier->addAction(_actionQuitter);
  connect(_actionQuitter, SIGNAL(triggered()), qApp,SLOT(quit()));
}

MainWindow::~MainWindow()
{
  if(_centralWidget!=NULL)
    delete _centralWidget;
  delete _actionQuitter;
}

void MainWindow::displayTransitionWidget(int number)
{
  if(_centralWidget!=NULL)
    delete _centralWidget;
  _centralWidget=new TransitionWidget(this,number);
  setCentralWidget(_centralWidget);
}

void MainWindow::displayFourChoicesWidget()
{
  if(_centralWidget!=NULL)
    delete _centralWidget;
  _centralWidget=new FourChoicesWidget(this);
  setCentralWidget(_centralWidget);
}

void MainWindow::createWidget()
{
  LevelType type=_enginePtr->getLevelPtr()->getLevelType();
  if(type==FourChoices)
    displayFourChoicesWidget();
}

void MainWindow::nextLevel(int link)
{
  QString linkText=getEnginePtr()->getLevelPtr()->getLink(link);
  getEnginePtr()->chooseLevel(linkText.toStdString());
  createWidget();
}
