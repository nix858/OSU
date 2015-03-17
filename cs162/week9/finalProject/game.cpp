#include "game.h"
#include "gameState.h"
#include "gameEntity.h"
#include "location.h"
#include "bounty.h"
#include "question.h"
#include "person.h"
#include "menu.h"
#include "random.h"
#include "area.h"
#include "planet.h"
#include "invitem.h"
#include <stack>

void Game::start() {
  system("clear");
  loadBounties();
  gameState = new GameState();
  gameState->money = 50000;
  Location* space = buildSolarSystem();
  gameState->currentLocation = space;
  gameState->locationHistory = new stack<GameEntity*>();

  cout << "Hello Bounty Hunter! Capture your bounty before you run out of money." << endl;
  cout << "Get clues by traveling the solar system and taking to the people you meet." << endl;
  cout << "Remember nothing is free in space, but the reward is worth it!" << endl;
  cout << "Each location costs 100 to travel to. Choose wisely." << endl;
  cout << "Good luck Bounty Hunter!" << endl << endl;

  //Bounty Loop
  do {
    gameState->bountyCaptured = false;
    gameState->clueLevel = 1;
    Menu bountyMenu((char*)"Hello Bounty Hunter! Select a bounty to find: ", allBounties);
    Bounty* sel = (Bounty*)(bountyMenu.run());
    gameState->bounty = sel;
    gameState->bountyLocation = pickBountyLocation();
    cout << gameState->bountyLocation->getLabel();

    //Action Loop
    do {
      system("clear");
      bool cluesGathered = gameState->clueLevel > 3;
      if (cluesGathered && gameState->currentLocation == gameState->bountyLocation) {
        bountyChase();
      } else {
        cout << "Your Wallet: " << gameState->money << endl;
        
        cout << "Clues:" << endl; 
        for (uint i = 0; i < gameState->clues.size(); ++i)
        {
          cout << "\t" << gameState->clues[i] << endl;
        }
        cout << endl;
        
        cout << "inventory:" << endl; 
        for (uint i = 0; i < gameState->inventory.size(); ++i)
        {
          cout << "\t" << gameState->inventory[i]->getLabel() << endl;
        }
        cout << endl << endl;
        gameState->currentLocation->selectAction(gameState);
      }
    } while (gameState->money > 0 && !gameState->bountyCaptured);

  } while (gameState->money > 0);
  cout << "You have run out of money! Game Over." << endl;
}

Location* Game::pickBountyLocation() {
  Random rnd;
  int randomPlanetIndex = rnd.between(0, allAreas.size() - 1);
  Location* area = (Location*)allAreas[randomPlanetIndex];
  cout << area->getLabel()<< endl;
  return area;
}

void Game::bountyChase() {
  system("clear");
  int bonusPoints = 0;
  cout << "You found your bounty! Now you must catch him!" << endl;
  if (gameState->inventory.size() > 0)
  {
    cout << "Your inventory items will help you" << endl;
    for (uint i = 0; i < gameState->inventory.size(); ++i)
    {
      int points = ((InventoryItem*)gameState->inventory[i])->getPointValue();
      cout << gameState->inventory[i]->getLabel() << " + " << points << endl;
      bonusPoints += points;
    }
  }

  Random rnd;
  int bountyPoints = rnd.between(1,10);
  int yourPoints = rnd.between(1,10);
  
  cout << "Bounty points: " << bountyPoints << endl;
  cout << "Your points: " << yourPoints << "+ " << bonusPoints << endl;

  if (yourPoints + bonusPoints >= bountyPoints) {
    int value = gameState->bounty->getValue();
    cout << "You got your bounty! You collect: " << value << endl;
    gameState->money += value;
    gameState->bountyCaptured = true;
  } else {
    cout << "Oh no! he got away!";
    gameState->bountyLocation = pickBountyLocation();
  }
}

Location* Game::buildSolarSystem() {
  Location* ss = new Location();
  ss->setName("space");
  ss->addLocation(buildMars(ss));
  ss->addLocation(buildSaturn(ss));
  return ss;
}

Location* Game::buildMars(Location* space) {
  Planet* planet = new Planet();
  planet->setName("Mars");

  Area* clv = buildBar((char*)"Cest La Vie (Bar)");
  clv->addClue(1, "He hasn't been seen on Earth in months");
  clv->addClue(2, "I think his sister lives on Mars");
  clv->addClue(3, "He has a thing for french bars");

  Area* ec = buildBar((char*)"El Capitan (Bar)");
  ec->addClue(1, "He hasn't been seen on Saturn in months");
  ec->addClue(2, "I think his sister lives on Mars");
  ec->addClue(3, "He has a thing for Mexican bars");

  Area* bebop = new Area();
  bebop->setName("Bebop (your ship)");
  bebop->north = clv;
  bebop->addLocation(space);

  clv->east = ec;
  clv->south = bebop;

  ec->west = clv;


  planet->setShip(bebop);

  allAreas.push_back(clv);
  allAreas.push_back(ec);

  return planet;
}

Location* Game::buildSaturn(Location* space) {
  Planet* planet = new Planet();
  planet->setName("Saturn");

  Area* titan = buildStation((char*)"Titan Police Station");
  titan->addClue(1, "He hasn't been seen on Venus in months");
  titan->addClue(2, "Last I heard he was going to earth.");
  titan->addClue(3, "I hear he likes to gamble.");


  Area* lc = buildBar((char*)"Last Call (Bar)");
  lc->addClue(1, "He hasn't been seen on Saturn in months");
  lc->addClue(2, "He used to live on Venus.");
  lc->addClue(3, "He doesn't drink.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = titan;
  bebop->east = lc;

  bebop->addLocation(space);

  titan->south = bebop;
  lc->west = bebop;

  planet->setShip(bebop);

  allAreas.push_back(titan);
  allAreas.push_back(lc);

  return planet;
}

Location* Game::buildEarth(Location* space) {
  Planet* planet = new Planet();
  planet->setName("Earth");

  Area* meteorField = buildMeteorField((char*)"Meteor Field");
  meteorField->addClue(1, "He hasn't been seen on Venus in months");
  meteorField->addClue(2, "Last I heard he was going to earth.");
  meteorField->addClue(3, "I hear he likes to gamble.");

  Area* Molly = buildBar((char*)"Molly's (Bar)");
  Molly->addClue(1, "He hasn't been seen on Saturn in months");
  Molly->addClue(2, "He used to live on Venus.");
  Molly->addClue(3, "He's a big drinker.");

  Area* store = buildStore((char*)"The Store");
  store->addClue(1, "He haven't seen him in months.");
  store->addClue(2, "He has family on Jupiter.");
  store->addClue(3, "He doesn't drink.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = Molly;
  bebop->east = meteorField;
  bebop->west = store;
  bebop->south = NULL;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  allAreas.push_back(meteorField);
  allAreas.push_back(Molly);
  allAreas.push_back(store);
  
  return planet;
}

Location* Game::buildVenus(Location* space) {
  Location* planet = new Location();
  planet->setName("Venus");

  Area* generalStore = buildStore((char*)"generalStore");
  generalStore->addClue(1, "He hasn't been seen on Venus in months");
  generalStore->addClue(2, "Last I heard he was going to earth.");
  generalStore->addClue(3, "I hear he likes to gamble.");

  Area* we = buildBar((char*)"World's End (Bar)");
  we->addClue(1, "He hasn't been seen on Saturn in months");
  we->addClue(2, "He used to live on Venus.");
  we->addClue(3, "He's a big drinker.");

  Area* ps = buildStation((char*)"Venus Police Station");
  ps->addClue(1, "He haven't seen him in months.");
  ps->addClue(2, "He has family on Jupiter.");
  ps->addClue(3, "He doesn't drink.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = ps;
  bebop->east = generalStore;
  bebop->west = NULL;
  bebop->south = we;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  allAreas.push_back(generalStore);
  allAreas.push_back(we);
  allAreas.push_back(ps);

  return planet;
}
 

Location* Game::buildNeptune(Location* space) {
  Location* planet = new Location();
  planet->setName("Neptune");

  Area* bd = buildDiner((char*)"Bob's Diner");
  bd->addClue(1, "He hasn't been seen on Venus in months");
  bd->addClue(2, "Last I heard he was going to earth.");
  bd->addClue(3, "I hear he likes to gamble.");

  Area* mf = buildMeteorField((char*)"Meteor Field");
  mf->addClue(1, "He hasn't been seen on Saturn in months");
  mf->addClue(2, "He used to live on Venus.");
  mf->addClue(3, "He's a big drinker.");

  Area* nml = buildStore((char*)"No Man's Land (Store)");
  nml->addClue(1, "He haven't seen him in months.");
  nml->addClue(2, "He has family on Jupiter.");
  nml->addClue(3, "He doesn't drink.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = NULL;
  bebop->east = mf;
  bebop->west = nml;
  bebop->south = bd;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  allAreas.push_back(bd);
  allAreas.push_back(mf);
  allAreas.push_back(nml);

  return planet;
}

Location* Game::buildMercury(Location* space) {
  Location* planet = new Location();
  planet->setName("Mercury");

  Area* meteorField = buildMeteorField((char*)"Meteor Field");
  meteorField->addClue(1, "He hasn't been seen on Venus in months");
  meteorField->addClue(2, "Last I heard he was going to earth.");
  meteorField->addClue(3, "I hear he likes to gamble.");

  Area* lc = buildBar((char*)"Last Call (Bar)");
  lc->addClue(1, "He hasn't been seen on Saturn in months");
  lc->addClue(2, "He used to live on Venus.");
  lc->addClue(3, "He's a big drinker.");

  Area* casino = buildCasino((char*)"Casino");
  casino->addClue(1, "He haven't seen him in months.");
  casino->addClue(2, "He has family on Jupiter.");
  casino->addClue(3, "He doesn't drink.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = casino;
  bebop->east = meteorField;
  bebop->south = NULL;
  bebop->west = lc;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  return planet;
}

Location* Game::buildPluto(Location* space) {
  Location* planet = new Location();
  planet->setName("Pluto");

  Area* policeStation = buildStation((char*)"Pluto Police Station");
  policeStation->addClue(1, "He hasn't been seen on Venus in months");
  policeStation->addClue(2, "Last I heard he was going to earth.");
  policeStation->addClue(3, "I hear he likes to gamble.");

  Area* cellar = buildBar((char*)"The Cellar (Bar)");
  cellar->addClue(1, "He hasn't been seen on Saturn in months");
  cellar->addClue(2, "He used to live on Venus.");
  cellar->addClue(3, "He's a big drinker.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = NULL;
  bebop->east = policeStation;
  bebop->west = cellar;
  bebop->south = NULL;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  allAreas.push_back(cellar);
  allAreas.push_back(policeStation);

  return planet;
}

Location* Game::buildUranus(Location* space) {
  Location* planet = new Location();
  planet->setName("Uranus");

  Area* meteorField = buildMeteorField((char*)"Meteor Field");
  meteorField->addClue(1, "He hasn't been seen on Venus in months");
  meteorField->addClue(2, "Last I heard he was going to earth.");
  meteorField->addClue(3, "I hear he likes to gamble.");

  Area* lc = buildBar((char*)"Last Call (Bar)");
  lc->addClue(1, "He hasn't been seen on Saturn in months");
  lc->addClue(2, "He used to live on Venus.");
  lc->addClue(3, "He's a big drinker.");

  Area* nml = buildStore((char*)"No Man's Land (Store)");
  nml->addClue(1, "He haven't seen him in months.");
  nml->addClue(2, "He has family on Jupiter.");
  nml->addClue(3, "He doesn't drink.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = lc;
  bebop->east = meteorField;
  bebop->west = nml;
  bebop->south = NULL;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  allAreas.push_back(meteorField);
  allAreas.push_back(lc);
  allAreas.push_back(nml);

  return planet;
}

Location* Game::buildJupiter(Location* space) {
  Location* planet = new Location();
  planet->setName("Jupiter");

  Area* ld = buildDiner((char*)"Lou's Diner");
  ld->addClue(1, "He hasn't been seen on Venus in months");
  ld->addClue(2, "Last I heard he was going to earth.");
  ld->addClue(3, "I hear he likes to gamble.");

  Area* cs = buildCasino((char*)"Casino");
  cs->addClue(1, "He hasn't been seen on Saturn in months");
  cs->addClue(2, "He used to live on Venus.");
  cs->addClue(3, "He's a big drinker.");

  Area* goods = buildStore((char*)"General Goods");
  goods->addClue(1, "He haven't seen him in months.");
  goods->addClue(2, "He has family on Jupiter.");
  goods->addClue(3, "He doesn't drink.");

  Area* ps = buildStation((char*)"Jupiter Police Station");
  ps->addClue(1, "He hasn't been seen on Venus in months");
  ps->addClue(2, "Last I heard he was going to earth.");
  ps->addClue(3, "I hear he likes to gamble.");

  Area* bebop = new Area();
  bebop->setName("Bebop (your Space ship)");
  bebop->north = ps;
  bebop->east = cs;
  bebop->west = goods;
  bebop->south = ld;
  bebop->addLocation(planet);

  planet->addLocation(bebop);

  allAreas.push_back(ld);
  allAreas.push_back(cs);
  allAreas.push_back(goods);
  allAreas.push_back(ps);

  return planet;
}

Area* Game::buildCasino(char* name) {
  Area* casino = new Area();
  casino->setName(name);
  
  //BlackJack dealer questions
  Question* playBlackJack = new Question("Deal me in.");
  playBlackJack->addAnswer("Check.");
  playBlackJack->addClueSegue("I like you.");
  playBlackJack->setCost(500);
  playBlackJack->setOdds(2);

  Question* blackJackLooking = new Question("Have you seen this person?");
  blackJackLooking->addAnswer("He doesn't look familiar.");
  blackJackLooking->addClueSegue("actually, now that you mention it");
  blackJackLooking->setCost(500);
  blackJackLooking->setOdds(1);

  Question* blackJackbribe = new Question("Have you seen this person?");
  blackJackbribe->addAnswer("Nope.");
  blackJackbribe->addClueSegue("You may have jogged my memory.");
  blackJackbribe->setCost(5000);
  blackJackbribe->setOdds(1);

  Person* blackJackDealer = new Person();
  blackJackDealer->addQuestion(playBlackJack);
  blackJackDealer->addQuestion(blackJackLooking);
  blackJackDealer->addQuestion(blackJackbribe);
  
  casino->addLocation(blackJackDealer);

  //gambler questions
  Question* gamblerQuestion = new Question("How's it going?");
  gamblerQuestion->addAnswer("I'm losing my shirt.");
  gamblerQuestion->addClueSegue("I guess I can help out a fellow gambler.");
  gamblerQuestion->setCost(500);
  gamblerQuestion->setOdds(2);

  Question* gamblerLooking = new Question("Have you seen this person?");
  gamblerLooking->addAnswer("Not that I remember.");
  gamblerLooking->addClueSegue("come to think of it");
  gamblerLooking->setCost(500);
  gamblerLooking->setOdds(1);

  Question* gamblerBribe = new Question("Have you seen this person?");
  gamblerBribe->addAnswer("He doesn't look familiar.");
  gamblerBribe->addClueSegue("You may have jogged my memory.");
  gamblerBribe->setCost(5000);
  gamblerBribe->setOdds(3);

  Person* gambler = new Person();
  gambler->addQuestion(gamblerQuestion);
  gambler->addQuestion(gamblerLooking);
  gambler->addQuestion(gamblerBribe);
  
  casino->addLocation(gambler);

  //cocktail waitress questions
  Question* cocktailWaitressQues = new Question("Can I get a wiskey?");
  cocktailWaitressQues->addAnswer("Sure doll.");
  cocktailWaitressQues->addClueSegue("You seem like a good guy.");
  cocktailWaitressQues->setCost(500);
  cocktailWaitressQues->setOdds(2);

  Question* cWlooking = new Question("Have you seen this person?");
  cWlooking->addAnswer("Not that I remember.");
  cWlooking->addClueSegue("come to think of it");
  cWlooking->setCost(500);
  cWlooking->setOdds(2);

  Question* cWbribe = new Question("Have you seen this person?");
  cWbribe->addAnswer("He doesn't look familiar.");
  cWbribe->addClueSegue("You may have jogged my memory.");
  cWbribe->setCost(5000);
  cWbribe->setOdds(1);

  Person* cocktailWaitress = new Person();
  cocktailWaitress->addQuestion(cocktailWaitressQues);
  cocktailWaitress->addQuestion(cWlooking);
  cocktailWaitress->addQuestion(cWbribe);
  
  casino->addLocation(cocktailWaitress);

  return casino;
}

Area* Game::buildDiner(char* name) {
  Area* diner = new Area();
  diner->setName(name);
  
  //Cook questions
  Question* cookQ = new Question("How's it going?");
  cookQ->addAnswer("Not bad.");
  cookQ->addClueSegue("You know what");
  cookQ->setCost(500);
  cookQ->setOdds(2);

  Question* cookLooking = new Question("Have you seen this person?");
  cookLooking->addAnswer("He doesn't look familiar.");
  cookLooking->addClueSegue("well actually");
  cookLooking->setCost(500);
  cookLooking->setOdds(1);

  Question* cookbribe = new Question("Have you seen this person?");
  cookbribe->addAnswer("Nope.");
  cookbribe->addClueSegue("Now that you mention it");
  cookbribe->setCost(5000);
  cookbribe->setOdds(1);

  Person* cook = new Person();
  cook->addQuestion(cookQ);
  cook->addQuestion(cookLooking);
  cook->addQuestion(cookbribe);
  
  diner->addLocation(cook);

  //customer questions
  Question* customerQ = new Question("How's it going?");
  customerQ->addAnswer("Just another day.");
  customerQ->addClueSegue("I may be able to help you out.");
  customerQ->setCost(500);
  customerQ->setOdds(2);

  Question* customerLooking = new Question("Have you seen this person?");
  customerLooking->addAnswer("I don't think so.");
  customerLooking->addClueSegue("come to think of it");
  customerLooking->setCost(500);
  customerLooking->setOdds(1);

  Question* customerBribe = new Question("Have you seen this person?");
  customerBribe->addAnswer("Never before.");
  customerBribe->addClueSegue("You may have jogged my memory.");
  customerBribe->setCost(5000);
  customerBribe->setOdds(3);

  Person* customer = new Person();
  customer->addQuestion(customerQ);
  customer->addQuestion(customerLooking);
  customer->addQuestion(customerBribe);
  
  diner->addLocation(customer);

  //waitress questions
  Question* cocktailWaitressQ = new Question("Can I get a burger?");
  cocktailWaitressQ->addAnswer("Sure doll.");
  cocktailWaitressQ->addClueSegue("You seem like a nice guy.");
  cocktailWaitressQ->setCost(500);
  cocktailWaitressQ->setOdds(2);

  Question* wlooking = new Question("Have you seen this person?");
  wlooking->addAnswer("Not that I remember.");
  wlooking->addClueSegue("come to think of it");
  wlooking->setCost(500);
  wlooking->setOdds(2);

  Question* wbribe = new Question("Have you seen this person?");
  wbribe->addAnswer("He doesn't look familiar.");
  wbribe->addClueSegue("You may have jogged my memory.");
  wbribe->setCost(5000);
  wbribe->setOdds(1);

  Person* waitress = new Person();
  waitress->addQuestion(cocktailWaitressQ);
  waitress->addQuestion(wlooking);
  waitress->addQuestion(wbribe);
  
  diner->addLocation(waitress);

  return diner;
}

Area* Game::buildStore(char* name) {
  Area* diner = new Area();
  diner->setName(name);
  
  //Clerk questions
  Question* clerkQ = new Question("How's it going?");
  clerkQ->addAnswer("Not bad.");
  clerkQ->addClueSegue("You know what");
  clerkQ->setCost(500);
  clerkQ->setOdds(2);

  Question* clerkLooking = new Question("Have you seen this person?");
  clerkLooking->addAnswer("He doesn't look familiar.");
  clerkLooking->addClueSegue("well actually");
  clerkLooking->setCost(500);
  clerkLooking->setOdds(1);

  Question* clerkbribe = new Question("Have you seen this person?");
  clerkbribe->addAnswer("Nope.");
  clerkbribe->addClueSegue("Now that you mention it");
  clerkbribe->setCost(5000);
  clerkbribe->setOdds(1);

  Person* clerk = new Person();
  clerk->addQuestion(clerkQ);
  clerk->addQuestion(clerkLooking);
  clerk->addQuestion(clerkbribe);
  
  diner->addLocation(clerk);

  //customer questions
  Question* customerQ = new Question("How's it going?");
  customerQ->addAnswer("Just another day.");
  customerQ->addClueSegue("I may be able to help you out.");
  customerQ->setCost(500);
  customerQ->setOdds(2);

  Question* customerLooking = new Question("Have you seen this person?");
  customerLooking->addAnswer("I don't think so.");
  customerLooking->addClueSegue("come to think of it");
  customerLooking->setCost(500);
  customerLooking->setOdds(1);

  Question* customerBribe = new Question("Have you seen this person?");
  customerBribe->addAnswer("Never before.");
  customerBribe->addClueSegue("You may have jogged my memory.");
  customerBribe->setCost(5000);
  customerBribe->setOdds(3);

  Person* customer = new Person();
  customer->addQuestion(customerQ);
  customer->addQuestion(customerLooking);
  customer->addQuestion(customerBribe);
  
  diner->addLocation(customer);

  //waitress questions
  Question* cocktailWaitressQ = new Question("Can I get a burger?");
  cocktailWaitressQ->addAnswer("Sure doll.");
  cocktailWaitressQ->addClueSegue("You seem like a nice guy.");
  cocktailWaitressQ->setCost(500);
  cocktailWaitressQ->setOdds(2);

  Question* wlooking = new Question("Have you seen this person?");
  wlooking->addAnswer("Not that I remember.");
  wlooking->addClueSegue("come to think of it");
  wlooking->setCost(500);
  wlooking->setOdds(2);

  Question* cWbribe = new Question("Have you seen this person?");
  cWbribe->addAnswer("He doesn't look familiar.");
  cWbribe->addClueSegue("You may have jogged my memory.");
  cWbribe->setCost(5000);
  cWbribe->setOdds(1);

  Person* waitress = new Person();
  waitress->addQuestion(cocktailWaitressQ);
  waitress->addQuestion(wlooking);
  waitress->addQuestion(cWbribe);
  
  diner->addLocation(waitress);

  return diner;
}

Person* Game::buildClerk(char* name) {
  //Station Clerk questions
  Question* sclerkQ = new Question("How's it going?");
  sclerkQ->addAnswer("Not bad.");
  sclerkQ->addClueSegue("You know what");
  sclerkQ->setCost(500);
  sclerkQ->setOdds(2);

  Question* sclerkLooking = new Question("Have you seen this person?");
  sclerkLooking->addAnswer("He doesn't look familiar.");
  sclerkLooking->addClueSegue("well actually");
  sclerkLooking->setCost(500);
  sclerkLooking->setOdds(1);

  Question* sclerkbribe = new Question("Have you seen this person?");
  sclerkbribe->addAnswer("Nope.");
  sclerkbribe->addClueSegue("Now that you mention it");
  sclerkbribe->setCost(5000);
  sclerkbribe->setOdds(1);

  Question* buyHandcuffs = new Question("Buy Handcuffs");
  buyHandcuffs->addAnswer("Here you go");
  buyHandcuffs->setCost(10000);
  InventoryItem* handcuffs = new InventoryItem();
  handcuffs->setLabel("handcuffs");
  handcuffs->setPointValue(2);
  buyHandcuffs->saleItem = (GameEntity*)handcuffs;
  
  Person* sclerk = new Person();
  sclerk->addQuestion(sclerkQ);
  sclerk->addQuestion(sclerkLooking);
  sclerk->addQuestion(sclerkbribe);
  sclerk->addQuestion(buyHandcuffs);
  sclerk->setName(name);
  
  return sclerk;
}

Area* Game::buildStation(char* name) {
  Area* station = new Area();
  station->setName(name);
  station->addLocation(buildClerk((char*)"Clerk"));

  //prisoner questions
  Question* prisonerQ = new Question("How's it going?");
  prisonerQ->addAnswer("Just another day.");
  prisonerQ->addClueSegue("I may be able to help you out.");
  prisonerQ->setCost(500);
  prisonerQ->setOdds(2);

  Question* prisonerLooking = new Question("Have you seen this person?");
  prisonerLooking->addAnswer("I don't think so.");
  prisonerLooking->addClueSegue("come to think of it");
  prisonerLooking->setCost(500);
  prisonerLooking->setOdds(1);

  Question* prisonerBribe = new Question("Have you seen this person?");
  prisonerBribe->addAnswer("What do you think?");
  prisonerBribe->addClueSegue("I'm feeling generous today");
  prisonerBribe->setCost(5000);
  prisonerBribe->setOdds(3);

  Person* prisoner = new Person();
  prisoner->addQuestion(prisonerQ);
  prisoner->addQuestion(prisonerLooking);
  prisoner->addQuestion(prisonerBribe);
  
  station->addLocation(prisoner);

  //cop questions
  Question* copQ = new Question("Can I get a burger?");
  copQ->addAnswer("Sure doll.");
  copQ->addClueSegue("You seem like a nice guy.");
  copQ->setCost(500);
  copQ->setOdds(2);

  Question* coplooking = new Question("Have you seen this person?");
  coplooking->addAnswer("Not that I remember.");
  coplooking->addClueSegue("come to think of it");
  coplooking->setCost(500);
  coplooking->setOdds(2);

  Question* copbribe = new Question("Have you seen this person?");
  copbribe->addAnswer("He doesn't look familiar.");
  copbribe->addClueSegue("You may have jogged my memory.");
  copbribe->setCost(5000);
  copbribe->setOdds(1);

  Person* cop = new Person();
  cop->addQuestion(copQ);
  cop->addQuestion(coplooking);
  cop->addQuestion(copbribe);
  
  station->addLocation(cop);

  return station;
}

Area* Game::buildMeteorField(char* name) {
  Area* meteorField = new Area();
  meteorField->setName(name);
  
  //Station Clerk questions
  Question* eclerkQ = new Question("How's it going?");
  eclerkQ->addAnswer("Not bad.");
  eclerkQ->addClueSegue("You know what");
  eclerkQ->setCost(500);
  eclerkQ->setOdds(2);

  Question* ecLooking = new Question("Have you seen this person?");
  ecLooking->addAnswer("He doesn't look familiar.");
  ecLooking->addClueSegue("well actually");
  ecLooking->setCost(500);
  ecLooking->setOdds(1);

  Question* ecbribe = new Question("Have you seen this person?");
  ecbribe->addAnswer("Nope.");
  ecbribe->addClueSegue("Now that you mention it");
  ecbribe->setCost(5000);
  ecbribe->setOdds(1);
  
  Person* eclerk = new Person();
  eclerk->addQuestion(eclerkQ);
  eclerk->addQuestion(ecLooking);
  eclerk->addQuestion(ecbribe);
  
  meteorField->addLocation(eclerk);

  //gounds crew questions
  Question* gcq = new Question("How's it going?");
  gcq->addAnswer("Just another day.");
  gcq->addClueSegue("I may be able to help you out.");
  gcq->setCost(500);
  gcq->setOdds(2);

  Question* gcLooking = new Question("Have you seen this person?");
  gcLooking->addAnswer("I don't think so.");
  gcLooking->addClueSegue("come to think of it");
  gcLooking->setCost(500);
  gcLooking->setOdds(1);

  Question* gcBribe = new Question("Have you seen this person?");
  gcBribe->addAnswer("What do you think?");
  gcBribe->addClueSegue("I'm feeling generous today");
  gcBribe->setCost(5000);
  gcBribe->setOdds(3);

  Person* gc = new Person();
  gc->addQuestion(gcq);
  gc->addQuestion(gcLooking);
  gc->addQuestion(gcBribe);
  
  meteorField->addLocation(gc);

  //cop questions
  Question* touristQ = new Question("Can I get a burger?");
  touristQ->addAnswer("Sure doll.");
  touristQ->addClueSegue("You seem like a nice guy.");
  touristQ->setCost(500);
  touristQ->setOdds(2);

  Question* touristLooking = new Question("Have you seen this person?");
  touristLooking->addAnswer("Not that I remember.");
  touristLooking->addClueSegue("come to think of it");
  touristLooking->setCost(500);
  touristLooking->setOdds(2);

  Question* touristBribe = new Question("Have you seen this person?");
  touristBribe->addAnswer("He doesn't look familiar.");
  touristBribe->addClueSegue("Actually");
  touristBribe->setCost(5000);
  touristBribe->setOdds(1);

  Person* tourist = new Person();
  tourist->addQuestion(touristQ);
  tourist->addQuestion(touristLooking);
  tourist->addQuestion(touristBribe);
  
  meteorField->addLocation(tourist);

  return meteorField;
}

Area* Game::buildBar(char* name) {
  Area* bar = new Area();
  bar->setName(name);
  
  //Bar tender questions
  Question* getDrink = new Question("Give me a cowboy");
  getDrink->addAnswer("Bourbon with milk");
  getDrink->addClueSegue("Since you're a payin customer");
  getDrink->setCost(500);
  getDrink->setOdds(2);

  Question* looking = new Question("Have you seen this person?");
  looking->addAnswer("I don't think so");
  looking->addClueSegue("actually, now that you mention it");

  Question* bribe = new Question("Have you seen this person?");
  bribe->addAnswer("Nope.");
  bribe->addClueSegue("You may have jogged my memory.");
  bribe->setCost(5000);
  bribe->setOdds(1);

  Person* barTender = new Person();
  barTender->addQuestion(getDrink);
  barTender->addQuestion(looking);
  barTender->addQuestion(bribe);
  
  bar->addLocation(barTender);

  //patron questions
  Question* patronQ = new Question("How's it going?");
  patronQ->addAnswer("Can't complain.");
  patronQ->addClueSegue("Well I guess I can help you out.");
  patronQ->setCost(500);
  patronQ->setOdds(2);

  Question* patronLooking = new Question("Have you seen this person?");
  patronLooking->addAnswer("Not that I remember.");
  patronLooking->addClueSegue("come to think of it");
  patronLooking->setCost(500);
  patronLooking->setOdds(1);

  Question* patronBribe = new Question("Have you seen this person?");
  patronBribe->addAnswer("He doesn't look familiar.");
  patronBribe->addClueSegue("Oh now I remember");
  patronBribe->setCost(5000);
  patronBribe->setOdds(3);

  Person* patron = new Person();
  patron->addQuestion(patronQ);
  patron->addQuestion(patronLooking);
  patron->addQuestion(patronBribe);
  
  bar->addLocation(patron);

  return bar;
}

void Game::loadBounties() {
  Bounty* b1 = new Bounty();
  b1->setName("BAKER PANCHORERO");
  b1->setValue(25000);
  b1->setCrime("A petty bank robber.");
  allBounties.push_back(b1);

  Bounty* b2 = new Bounty();
  b2->setName("ASIMOV SOLENSAN");
  b2->setValue(50000);
  b2->setCrime("A common gangster who betrayed his employer.He is addicted to Red Eye.");
  allBounties.push_back(b2);

  Bounty* b3 = new Bounty();
  b3->setName("WITNEY HAGAS MATSUMOTO");
  b3->setValue(75000);
  b3->setCrime("A lowlife con artist who targets vulnerable women.");
  allBounties.push_back(b3);

  Bounty* b4 = new Bounty();
  b4->setName("CHESSMASTER HEX");
  b4->setValue(50000);
  b4->setCrime("A genius who helped develop the hyperspace gates.");
  allBounties.push_back(b4);

  Bounty* b5 = new Bounty();
  b5->setName("VINCENT VOLAJU");
  b5->setValue(10000);
  b5->setCrime("Titan War veteran who lost his mind and plans to destroy the world.");
  allBounties.push_back(b5);
}