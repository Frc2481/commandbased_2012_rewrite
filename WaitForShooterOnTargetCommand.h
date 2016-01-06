
class WaitForShooterOnTargetCommand : public CommandBase {

  WaitForShooterOnTargetCommand() : CommandBase("WaitForShooterOnTargetCommand") {

  }

  void Initialize() {}
  void Execute() {}
  bool IsFinished() {
    return m_shooter->isOnTarget();
  }
  void End() {}
  void Interrupted() {}
};
