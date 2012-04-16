#include "Engine.hpp"
#include "MainWindow.hpp"
#include <QApplication>
#include <QtGui>
int main(int argc, char** argv)
{
  QApplication app(argc,argv);
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
  Engine engine;
  engine.chooseLevel("01.xml");
  MainWindow mainWindow(&engine);
  mainWindow.show();
  mainWindow.createWidget();
  return app.exec();
}
