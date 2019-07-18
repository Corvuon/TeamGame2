#include "Engine.cpp"
#include "GameState.cpp"

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
                Aspen::Graphics::Colors::BLACK, true,
                // this is its parent and its name is "Rectangle" (this can be omitted)
                this, "Rectangle"
                )
            );
    }
};
class PlayerUnit : public Aspen::Object::Object
{
  Aspen::Graphics::Animation *hoverAnim;
  Aspen::Graphics::Graphics *hoverIdle;
  Aspen::Graphics::Animation *hoverDest;
  Aspen::Graphics::Animation *skidAnim;
  Aspen::Graphics::Animation *skidsecAnim;
  Aspen::Graphics::Animation *skidDest;
  Aspen::Graphics::Graphics *skidIdle;
  Aspen::Graphics::Animation *artilleryAnim;
  Aspen::Graphics::Animation *artyDest;
  Aspen::Graphics::Graphics *artyIdle;
  Aspen::Graphics::Animation *heavyAnim;
  Aspen::Graphics::Animation *heavyDest;
  Aspen::Graphics::Graphics *heavyIdle;
  Aspen::Graphics::Animation *hyperAnim;
  Aspen::Graphics::Animation *hyperAnimS;
  Aspen::Graphics::Animation *hyperAnimM;
  Aspen::Graphics::Animation *hyperAnimE;
  Aspen::Graphics::Animation *hyperDest;
  Aspen::Graphics::Graphics *hyperIdle;
  Aspen::Graphics::Animation *mechAnim;
  Aspen::Graphics::Animation *mechDest;
  Aspen::Graphics::Graphics *mechIdle;
  Aspen::Graphics::Graphics *legIdle;
  Aspen::Graphics::Animation *legTurnR;
  Aspen::Graphics::Animation *legTurnL;
  Aspen::Graphics::Animation *legWalkDiag;
  Aspen::Graphics::Animation *legWalkDiag2;
  Aspen::Graphics::Animation *legWalkHoriz;
  Aspen::Graphics::Animation *legWalkVert;
  bool hover = false;
  bool skid = false;
  bool artillery = false;
  bool heavyRepeater = false;
  bool hyperturret = false;
  bool mech = false;
  bool mechanized = false;
  public:
  PlayerUnit(Object *parent = nullptr, std::string name = "PlayerUnit")
  {
  hoverAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hoverAnim);
  hoverDest = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hoverDest);
  skidAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(skidAnim);
  skidsecAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(skidsecAnim);
  skidDest = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(skidDest);
  artilleryAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(artilleryAnim);
  artyDest = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(artyDest);
  hyperAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hyperAnim);
  hyperAnimS = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hyperAnimS);
  hyperAnimM = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hyperAnimM);
  hyperAnimE = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hyperAnimE);
  hyperDest = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(hyperDest);
  heavyAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(heavyAnim);
  heavyDest = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(heavyDest);
  mechAnim = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(mechAnim);
  mechDest = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(mechDest);
  legWalkDiag = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(legWalkDiag);
  legWalkDiag2 = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(legWalkDiag2);
  legWalkHoriz = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(legWalkHoriz);
  legWalkVert = new Aspen::Graphics::Animation(
    new Aspen::Graphics::UniformSpritesheet("./resources/Firing Cycle.png", 32, 32, 8, nullptr, "FiringCycle"), 1.0f / 12.0f, this, "Firing Cycle");
    AddChild(legWalkVert);

  skidAnim->Deactivate();
  

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
  }*/

  }
//
   //  void OnUpdate()
   //{
   //   double xv = moveable->GetRigidbody()->GetVelocityX();
   //   double yv = moveable->GetRigidbody()->GetVelocityY();
//
   //   if (Aspen::Input::KeyHeld(SDLK_a)){
   //     xv = -5;
   //   }if (Aspen::Input::KeyHeld(SDLK_d)){
   //     xv = 5;
   //   }if (Aspen::Input::KeyHeld(SDLK_w)){
   //     yv = -5;
   //  }if (Aspen::Input::KeyHeld(SDLK_s)){
   //    yv = 5;
   //   }
   //  moveable->GetRigidbody()->SetCartesianVelocity(xv, yv);
   // }
};
class EnemyUnit : Aspen::Graphics::Animation
{

};

int main(int argc, char **argv)
{
    Aspen::Engine::Engine engine(Aspen::Engine::START_FLAGS::ALL);

    engine.FindChildOfType<Aspen::GameState::GameStateManager>()->LoadState<MyState>(true);

    while (engine)
        engine();
    return 0;
}
