#include "game.h"
#include "gameState.h"
#include "gameEntity.h"
#include "location.h"
#include "bounty.h"
#include "question.h"
#include "person.h"
#include "menu.h"
#include "random.h"
#include <stack>

void Game::start() {
  loadBounties();
  gameState = new GameState();
  gameState->money = 50000;
  Location* space = buildSolarSystem();
  gameState->currentLocation = space;
  gameState->locationHistory = new stack<GameEntity*>();
  
  //Bounty Loop
  do {
    gameState->bountyCaptured = false;
    gameState->clueLevel = 1;
    Menu bountyMenu((char*)"Select a bounty", allBounties);
    Bounty* sel = (Bounty*)(bountyMenu.run());
    gameState->bounty = sel;
    gameState->bountyLocation = pickBountyLocation(space);

    //Action Loop
    do {
      system("clear");
      if (gameState->currentLocation == gameState->bountyLocation)
      {
        int value = gameState->bounty->getValue();
        cout << "You found your bounty! You collect: " << value << endl;
        // TODO: bounty chase
        gameState->money += value;
        gameState->bountyCaptured = true;
      } else {
        cout << "Money: " << gameState->money << endl << endl;
        gameState->currentLocation->selectAction(gameState);
      }
    } while (gameState->money > 0 && !gameState->bountyCaptured);

  } while (gameState->money > 0);
  cout << "You have run out of money! Game Over." << endl;
}

Location* Game::pickBountyLocation(Location* space) {
  Random rnd;
  
  int randomPlanetIndex = rnd.between(0, space->locations.size() - 1);
  Location* planet = (Location*)space->locations[randomPlanetIndex];

  int randomAreaIndex = rnd.between(0, planet->locations.size() - 1);
  cout << "Area: " << randomAreaIndex << " max " << planet->locations.size() - 1 << endl;
  Location* area =  (Location*)planet->locations[randomAreaIndex];
  
  return area;
}

Location* Game::buildSolarSystem() {
  Location* ss = new Location();
  ss->setName("space");
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