#include "Engine.hpp"
#include "Effect.hpp"
#include "FourChoicesWidget.hpp"
#include "FourChoicesLevel.hpp"
Engine::Engine():_levelPtr(NULL)
{
  QList<Skill> skills;
  _playerPtr=new People(100,90,skills);
}

Engine::~Engine()
{
  delete _playerPtr;
  if(_levelPtr!=NULL)
    delete _levelPtr;
}

void Engine::chooseLevel(const std::string & link )
{
  QString levelType;
  TiXmlDocument documentXml(link);
  if(!documentXml.LoadFile()){
    std::cerr << "erreur lors du chargement" << std::endl;
    std::cerr << "error #" << documentXml.ErrorId() << " : " << documentXml.ErrorDesc() << std::endl;
  }
  TiXmlElement *elem=documentXml.FirstChildElement();
  levelType=elem->Attribute("type");
  if(levelType=="fourChoices")
    parseFourChoices(documentXml);
}

void Engine::parseFourChoices(TiXmlDocument & xmlDocument)
{
  int i,hp,cp;
  LevelType type=FourChoices;
  TiXmlHandle handle(&xmlDocument);
  TiXmlElement *elem=handle.FirstChildElement().Element();
  QString text,buttonText,effectText,linkText;
  QList<QString> buttonsName,effectTextList,linkList;
  QList<Effect> effectList;
  text=elem->Attribute("text");
  elem=handle.FirstChildElement().FirstChildElement().Element();
  for(i=0;i<4;++i)
    {
      elem->QueryIntAttribute("effectHp", &hp);
      elem->QueryIntAttribute("effectCp", &cp);
      Effect effect(hp,cp);
      effectList.append(effect);
      buttonText=elem->Attribute("enonce");
      buttonsName.append(buttonText);
      effectText=elem->Attribute("textEffect");
      effectTextList.append(effectText);
      linkText=elem->Attribute("link");
      linkList.append(linkText);
      elem=elem->NextSiblingElement();
    }
  if(_levelPtr!=NULL)
    delete _levelPtr;
  _levelPtr=new FourChoicesLevel(text,buttonsName,effectTextList,linkList,type,effectList);
}

void Engine::applyEffect(int number)
{
  Effect effect=_levelPtr->getEffect(number);
  int hp=_playerPtr->getHp();
  int cp=_playerPtr->getCp();
  hp+=effect.getHp();
  cp+=effect.getCp();
  _playerPtr->setHp(hp);
  _playerPtr->setCp(cp);
}

