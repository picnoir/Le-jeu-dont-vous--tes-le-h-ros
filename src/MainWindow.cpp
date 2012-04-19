#include "MainWindow.hpp"
#include <QtGui>
#include <QFileDialog>
#include "Hud.hpp"
#include "CentralWidget.hpp"
MainWindow::MainWindow(Engine* enginePtr):_centralWidget(NULL),_enginePtr(enginePtr)
{
  _centralWidget=new CentralWidget(this);
  _menuFichier=menuBar()->addMenu("&Fichier");
  _actionQuitter=new QAction("&Quitter",this);
  _actionCharger=new QAction("&Charger",this);
  _actionSauver=new QAction("&Sauver",this);
  _actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
  _actionCharger->setShortcut(QKeySequence("Ctrl+C"));
  _actionSauver->setShortcut(QKeySequence("Ctrl+S"));
  _menuFichier->addAction(_actionCharger);
  _menuFichier->addAction(_actionSauver);
  _menuFichier->addAction(_actionQuitter);
  QObject::connect(_actionQuitter, SIGNAL(triggered()), qApp,SLOT(quit()));
  QObject::connect(_actionSauver,SIGNAL(triggered()), this, SLOT(save()));
  QObject::connect(_actionCharger,SIGNAL(triggered()), this, SLOT(load()));
}

void MainWindow::updateHud()
{
  int life,stamina;
  life=_enginePtr->getPlayerPtr()->getHp();
  stamina=_enginePtr->getPlayerPtr()->getCp();
  emit hp(life);
  emit cp(stamina);
}

MainWindow::~MainWindow()
{
  if(_centralWidget!=NULL)
    delete _centralWidget;
  delete _actionQuitter;
}

void MainWindow::save()
{
  QString file = QFileDialog::getSaveFileName(this, "Enregistrer une partie", QString(), "Parties (*.partie)");
 if(!file.endsWith(".partie"))
   file+=".partie";
 _enginePtr->saveGame(file);
}

void MainWindow::load()
{
  QString file = QFileDialog::getOpenFileName(this, "Charger une partie", QString(), "Parties (*.partie)");
  _enginePtr->loadGame(file);
  if(_centralWidget!=NULL)
    _centralWidget->deleteLater();
  _centralWidget= new CentralWidget(this);
}
