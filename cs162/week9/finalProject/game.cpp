#include "game.h"

void Game::start() {
  loadBounties();
  gameState = new GameState();
  gameState->money = 50000;
  Location space = buildSolarSystem();
  gameState->currentLocation = space;

  //Bounty Loop
  do
  {
    bountyCaptured = false;
    Menu bountyMenu(allBounties);
    gameState.bounty = (Bounty)bountyMenu.run();
    
    //Action Loop
    do
    {
      currentLocation->selectAction(gameState);
    } while (gameState->money > 0 && !gameState->bountyCaptured);

  } while (gameState->money > 0);
    
}

Location* buildSolarSystem() {
  Location ss;
  ss.addLocation(buildMars());
  return &ss;
}

Location* Game::buildMars() {
  Location planet;
  planet.setName("Mars");
  planet.addLocation(buildBar("Cest La Vie (Bar)"));
  planet.addLocation(buildBar("El Capitan (Bar)"));
  return &planet;
}

Location* Game::buildBar(string name) {
  Location bar;
  bar.setName(name);
  
  //Bar tender questions
  Question getDrink("Give me a cowboy");
  getDrink.addAnswer("Bourbon with milk")
  getDrink.addSegue("Since you're a payin customer")
  getDrink.setCost(500);

  Question looking("Have you seen this person?");
  looking.addAnswer("I don't think so");
  looking.addSegue("actually, now that you mention it")

  Question lookingBribe("Have you seen this person?");
  lookingBribe.addAnswer("nah");
  lookingBribe.addSegue("now we're talkin")
  lookingBribe.setCost(5000);

  barTender.addQuestion(getDrink);
  barTender.addQuestion(looking);
  barTender.addQuestion(lookingBribe);
  
  return &bar;
}

void Game::loadBounties() {
  //TODO: random select location;
  gameState->bountyLocation = locations[1];
}