#include "game.h"
#include "gameState.h"
#include "gameEntity.h"
#include "location.h"
#include "bounty.h"
#include "question.h"
#include "person.h"
#include "menu.h"

void Game::start() {
  loadBounties();
  gameState = new GameState();
  gameState->money = 50000;
  Location* space = buildSolarSystem();
  gameState->currentLocation = space;
  //TODO: random select location;
  gameState->bountyLocation = space->locations[0]->locations[1];
  //Bounty Loop
  do
  {
    gameState->bountyCaptured = false;
    Menu bountyMenu((char*)"Select a bounty", allBounties);
    Bounty* sel = (Bounty*)(bountyMenu.run());
    gameState->bounty = sel;
    
    //Action Loop
    do
    {
      gameState->currentLocation->selectAction(gameState);
    } while (gameState->money > 0 && !gameState->bountyCaptured);

  } while (gameState->money > 0);
    
}

Location* Game::buildSolarSystem() {
  Location* ss = new Location();
  ss->addLocation(buildMars());
  return ss;
}

Location* Game::buildMars() {
  Location* planet = new Location();
  planet->setName("Mars");
  planet->addLocation(buildBar((char*)"Cest La Vie (Bar)"));
  planet->addLocation(buildBar((char*)"El Capitan (Bar)"));
  return planet;
}

Location* Game::buildBar(char* name) {
  Location* bar = new Location();
  bar->setName(name);
  
  //Bar tender questions
  Question* getDrink = new Question("Give me a cowboy");
  getDrink->addAnswer("Bourbon with milk");
  getDrink->addClueSegue("Since you're a payin customer");
  getDrink->setCost(500);

  Question* looking = new Question("Have you seen this person?");
  looking->addAnswer("I don't think so");
  looking->addClueSegue("actually, now that you mention it");

  Question* lookingBribe = new Question("Have you seen this person?");
  lookingBribe->addAnswer("nah");
  lookingBribe->addClueSegue("now we're talkin");
  lookingBribe->setCost(5000);

  Person* barTender = new Person();
  barTender->addQuestion(getDrink);
  barTender->addQuestion(looking);
  barTender->addQuestion(lookingBribe);
  
  bar->addLocation(barTender);

  return bar;
}

void Game::loadBounties() {
  Bounty* b1 = new Bounty();
  b1->setName("Baker Pancharello");
  b1->setValue(25000);
  allBounties.push_back(b1);
}