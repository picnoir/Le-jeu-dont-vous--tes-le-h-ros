#include "MainWindow.hpp"
#include <QtGui>
#include "Hud.hpp"
#include "CentralWidget.hpp"
MainWindow::MainWindow(Engine* enginePtr):_centralWidget(NULL),_enginePtr(enginePtr)
{
  _centralWidget=new CentralWidget(this);
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

