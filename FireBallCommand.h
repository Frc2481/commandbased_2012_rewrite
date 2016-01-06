
class FireBallCommand : CommandBase {
public:
  bool m_skip;
  FireBallCommand() : CommandBase("FireBallCommand") {
    Require(m_lift);
  }

  void Initialize() {
    if (m_shooter->isOnTarget()) {
      m_skip = false;
      m_lift->liftOnFwd();
    } else {
      m_skip = true;
    }
  }

  void Execute() {}

  bool IsFinished() {
    return !m_lift->isBallAtTopSensor() || m_skip;
  }

  void End() {
    m_lift->liftOff();
  }

  void Interrupted() {
    End();
  }
};
