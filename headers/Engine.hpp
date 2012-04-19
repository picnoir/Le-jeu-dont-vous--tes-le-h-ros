/*
---Classe Engine
---Classe du moteur du jeu. C'est une classe centrale qui va permettre de parser le niveau et va gérer tout ce qui est non graphique
 */
#ifndef ENGINE
#define ENGINE
#include <string>
#include "Level.hpp"
#include "tinyxml.h"
#include "People.hpp"
class Engine
{
protected:
  std::string _currentLevel;
  People* _playerPtr;
  Level* _levelPtr;
public:
  Engine();
  void saveGame(const QString & file);
  void loadGame(const QString & file);
  Level* getLevelPtr(){return _levelPtr;}
  People* getPlayerPtr(){return _playerPtr;}
  void chooseLevel(const std::string & link);
  void parseFourChoices(TiXmlDocument & xmlDocument);
  bool applyEffect(int number);
  ~Engine();
};
#endif
