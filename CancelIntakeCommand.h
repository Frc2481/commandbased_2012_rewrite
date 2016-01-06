
class CancelIntakeCommand : public CommandBase {
public:

  CancelIntakeCommand() : CommandBase("CancelIntakeCommand") {
      Require(m_intake);
      Require(m_lift);
  }

  void Initialize() {}
  void Execute() {}
  bool IsFinished() {
    return true;
  }
  void End() {}
  void Interrupted() {}
  
};
