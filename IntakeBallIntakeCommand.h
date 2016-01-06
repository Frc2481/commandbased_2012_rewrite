

class IntakeBallIntakeCommand : CommandBase {
public:

  IntakeBallIntakeCommand() : CommandBase("IntakeBallIntakeCommand") {
    Require(m_intake);
  }

  void Initialize() {
      m_intake->OnFwd();
  }

  void Execute() {}

  bool IsFinished() {
    return m_intake->isBallAtBottomSensor();
  }

  void End() {
    m_intake->Off();
  }

  void Interrupted() {
    End();
  }
};
