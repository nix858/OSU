#include "game.h"
#include "gameState.h"
#include "gameEntity.h"
#include "location.h"
#include "bounty.h"
#include "question.h"
#include "person.h"
#include "menu.h"
#include <stack>

void Game::start() {
  loadBounties();
  gameState = new GameState();
  gameState->money = 50000;
  Location* space = buildSolarSystem();
  gameState->currentLocation = space;
  gameState->locationHistory = new stack<GameEntity*>();
  gameState->locationHistory->push(space);
  //TODO: random select location;
  Location* mars = (Location*)space->locations[0];

  gameState->bountyLocation = mars;
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

  Question* bribe = new Question("Have you seen this person?");
  bribe->addAnswer("nah");
  bribe->addClueSegue("now we're talkin");
  bribe->setCost(5000);

  Person* barTender = new Person();
  barTender->addQuestion(getDrink);
  barTender->addQuestion(looking);
  barTender->addQuestion(bribe);
  
  bar->addLocation(barTender);

  return bar;
}

void Game::loadBounties() {
  Bounty* b1 = new Bounty();
  b1->setName("Baker Pancharello");
  b1->setValue(25000);
  allBounties.push_back(b1);
}