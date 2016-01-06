
class VommitBallCommand : CommandBase {
public:
  VommitBallCommand() : CommandBase("VommitBallCommand") {
    Require(m_intake);
    Require(m_lift);
  }

  void Initialize() {
    m_intake->onRev();
    m_lift->liftOnRev();
  }

  void Execute() {}

  bool IsFinished() {
    return false;
  }

  void End() {}

  void Interrupted() {
    m_intake->off();
    m_lift->liftOff();
  }

};
