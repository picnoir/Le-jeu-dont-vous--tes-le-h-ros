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
  People* _playerPtr;
  Level* _levelPtr;
public:
  Engine();
  Level* getLevelPtr(){return _levelPtr;}
  void chooseLevel(const std::string & link);
  void parseFourChoices(TiXmlDocument & xmlDocument);
  ~Engine();
};
#endif
