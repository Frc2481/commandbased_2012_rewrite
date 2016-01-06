
class TurnOnShooterCommand : public CommandBase {
public:
  TurnOnShooterCommand() : CommandBase("TurnOnShooterCommand") {
    Require(m_shooter);
  }

  void Initialize() {
    m_shooter->setSpeed(4500);
    m_shooter->on();
  }

  void Execute() {}

  bool IsFinished() {
    return true;
  }

  void End() {}
  void Interrupted() {}
};
