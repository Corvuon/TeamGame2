#include "Engine.hpp"
#include "Graphics.hpp"
#include "UI.hpp"
#include "Transform.hpp"
#include "Controller.hpp"
#include "Physics.hpp"
#include "Time.hpp"
#include "Log.hpp"
#include "Audio.hpp"
#include "Input.hpp"
#include "Debug.hpp"
#include "GameState.hpp"
#include <iostream>

using Aspen::Engine::Engine;
using Aspen::GameState::GameState;
using Aspen::GameState::GameStateManager;
using Aspen::Graphics::Graphics;
using Aspen::Object::Object;


class PlayerUnit : public Aspen::Object::Object
{
  Aspen::Graphics::Animation *hoverAnim;
  Aspen::Graphics::Graphics *hoverIdle;
  //Aspen::Graphics::Animation *hoverDest;
  //Aspen::Graphics::Animation *skidAnim;
  //Aspen::Graphics::Animation *skidsecAnim;
  //Aspen::Graphics::Animation *skidDest;
  //Aspen::Graphics::Graphics *skidIdle;
  //Aspen::Graphics::Animation *artilleryAnim;
  //Aspen::Graphics::Animation *artyDest;
  //Aspen::Graphics::Graphics *artyIdle;
  //Aspen::Graphics::Animation *heavyAnim;
  //Aspen::Graphics::Animation *heavyDest;
  //Aspen::Graphics::Graphics *heavyIdle;
  //Aspen::Graphics::Animation *hyperAnim;
  //Aspen::Graphics::Animation *hyperAnimS;
  //Aspen::Graphics::Animation *hyperAnimM;
  //Aspen::Graphics::Animation *hyperAnimE;
  //Aspen::Graphics::Animation *hyperDest;
  //Aspen::Graphics::Graphics *hyperIdle;
  //Aspen::Graphics::Animation *mechAnim;
  //Aspen::Graphics::Animation *mechDest;
  //Aspen::Graphics::Graphics *mechIdle;
  //Aspen::Graphics::Graphics *legIdle;
  //Aspen::Graphics::Animation *legTurnR;
  //Aspen::Graphics::Animation *legTurnL;
  //Aspen::Graphics::Animation *legWalkDiag;
  //Aspen::Graphics::Animation *legWalkDiag2;
  //Aspen::Graphics::Animation *legWalkHoriz;
  //Aspen::Graphics::Animation *legWalkVert;
  //bool hover = false;
  //bool skid = false;
  //bool artillery = false;
  //bool heavyRepeater = false;
  //bool hyperturret = false;
  //bool mech = false;
  //bool mechanized = false;
  public:
  PlayerUnit(Object *parent = nullptr, std::string name = "PlayerUnit")
  {
  hoverAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Hover firecycle centered.png", 32, 32, 8, nullptr, "Hover firecycle centered"), 1.0f / 12.0f, this, "Hover firecycle centered");
    AddChild(hoverAnim);
  //hoverDest = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Hover destruction.png", 32, 32, 8, nullptr, "Hover Destruction"), 1.0f / 12.0f, this, "Hover Destruction");
  //  AddChild(hoverDest);
  //skidAnim = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(skidAnim);
  //skidsecAnim = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(skidsecAnim);
  //skidDest = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(skidDest);
  //artilleryAnim = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(artilleryAnim);
  //artyDest = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(artyDest);
  //hyperAnim = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(hyperAnim);
  //hyperAnimS = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(hyperAnimS);
  //hyperAnimM = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(hyperAnimM);
  //hyperAnimE = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(hyperAnimE);
  //hyperDest = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(hyperDest);
  //heavyAnim = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(heavyAnim);
  //heavyDest = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(heavyDest);
  //mechAnim = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(mechAnim);
  //mechDest = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(mechDest);
  //legWalkDiag = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(legWalkDiag);
  //legWalkDiag2 = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(legWalkDiag2);
  //legWalkHoriz = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(legWalkHoriz);
  //legWalkVert = new Aspen::Graphics::Animation(
  //  new Aspen::Graphics::UniformSpritesheet("./resources/Sprites/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
  //  AddChild(legWalkVert);

  AddChild(hoverAnim);
    CreateChild<Aspen::Transform::Transform>();
      GetTransform()->SetPosition(100,100);
    CreateChild<Aspen::Physics::AABBCollider>()->SetSize(32,32);
    CreateChild<Aspen::Physics::Rigidbody>();


  /*void buildHover(){
    hover = true;
  }
  void buildSkid(){
    skid = true;
  }
  void buildArty(){
    artillery = true;
    mechanized = true;
  }
  void buildArty(){
    PlayerUnit *Arty;
    Arty->artillery = true;
    Arty->mechanized = true;
  }
  void buildMech(){
    Aspen::Graphics::Animation *Mech;
    Mech = new Aspen::Graphics::Animation(new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 0.0f, this, "Firing Cycle");
  */}

  
     void OnUpdate()
    {
      double xv = GetRigidbody()->GetVelocityX();
      double yv = GetRigidbody()->GetVelocityY();
      if (Aspen::Input::KeyHeld(SDLK_a)){
        xv = -1;
        Aspen::Log::Info("A key is held");
      }if (Aspen::Input::KeyHeld(SDLK_d)){
        xv = 1;
        Aspen::Log::Info("D key is held");
      }if (Aspen::Input::KeyHeld(SDLK_w)){ 
        yv = -1;
        Aspen::Log::Info("W key is held");
     }if (Aspen::Input::KeyHeld(SDLK_s)){
       yv = 1;
       Aspen::Log::Info("S key is held");
      }
      GetRigidbody()->SetCartesianVelocity(xv, yv);
    }
    void OnMouseClick(){
      
    };
};

/* class EnemyUnit : public Aspen::Object::Object
{
   Aspen::Graphics::Animation *animation;
  public:
    EnemyUnit(Object *parent = nullptr, std::string name = "Eunit") : Object (parent, name)
    {
      animation = new Aspen::Graphics::Animation(
        new Aspen::Graphics::UniformSpritesheet("./resources/Enemy Skid destruction (1).png",32,32,1,nullptr,"jim"),
        1.0f/12.0f, parent, name);
      AddChild(animation);
      CreateChild<Aspen::Transform::Transform>();
      GetTransform()->SetPosition(100,100);
      CreateChild<Aspen::Physics::AABBCollider>()->SetSize(55,120);
      CreateChild<Aspen::Physics::Rigidbody>();
    }
};
*/
class MyState : public Aspen::GameState::GameState
{
public:
    MyState(Aspen::Object::Object *parent = nullptr, std::string name = "My State")
      : Aspen::GameState::GameState(parent, name)
    {
        // Create a new child
        AddChild(
            // The child is a new rectangle
            new Aspen::Graphics::Rectangle(
                // x = 0, y = 0, width = 32, height = 32
                SDL_Rect({0, 0, 32, 32}),
                // It's black and filled
                Aspen::Graphics::Colors::BLUE, true,
                // this is its parent and its name is "Rectangle" (this can be omitted)
                this, "BlueBase"
                )
            );
        AddChild(
            new Aspen::Graphics::Rectangle(
                // x = 0, y = 0, width = 32, height = 32
                SDL_Rect({0, 0, 32, 32}),
                // It's black and filled
                Aspen::Graphics::Colors::RED, true,
                // this is its parent and its name is "Rectangle" (this can be omitted)
                this, "RedBase"
                )
            );
        CreateChild<PlayerUnit>();
    }
};
int main(int argc, char **argv)
{
    //int resource = 155;
    //void OnUpdate(){
    //    main.resource++;
    //};
    Aspen::Engine::Engine engine(Aspen::Engine::START_FLAGS::ALL);
    engine.FindChildOfType<Aspen::Physics::Physics>()->SetGravityStrength(0);
    engine.FindChildOfType<Aspen::Physics::Physics>()->SetDrag(0.5f);
    engine.FindChildOfType<Aspen::GameState::GameStateManager>()->LoadState<MyState>(true);
    

    while (engine)
        engine();
    return 0;
}
