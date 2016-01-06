
#include Lift.h

class ArmBallCommand : CommandBase {
public:

  ArmBallCommand() : CommandBase("ArmBallCommand") {
    Require(m_lift);
  }

  void Initialize() {
    m_lift->liftOnFwd();
  }

  void Execute() {}

  bool IsFinished() {
    return m_lift->isBallAtTopSensor();
  }

  void End() {
    m_lift->liftOff();
  }

  void Interrupted() {
    End();
  }
};
