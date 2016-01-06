
class IntakeBallLiftCommand : CommandBase {
public:

  IntakeBallLiftCommand() : CommandBase("IntakeBallLiftCommand") {
    Require(m_lift);
  }

  void Initialize() {
      m_lift->liftOnFwd();
  }

  void Execute() {}

  bool IsFinished() {
    return m_lift->isBallAtMidSensor();
  }

  void End() {
    m_lift->liftOff();
  }

  void Interrupted() {
    End();
  }
};
