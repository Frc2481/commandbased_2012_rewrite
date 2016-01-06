
class TurnOffShooterCommand : public CommandBase {
public:
  TurnOffShooterCommand() : CommandBase("TurnOffShooterCommand") {
    Require(m_shooter);
  }

  void Initialize() {    
    m_shooter->off();
  }

  void Execute() {}

  bool IsFinished() {
    return true;
  }

  void End() {}
  void Interrupted() {}
};
