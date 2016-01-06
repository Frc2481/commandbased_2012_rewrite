
class TwoBallAutoCommandGroup : public CommandGroup {

  TwoBallAutoCommandGroup() : CommandGroup("TwoBallAutoCommandGroup") {
    AddParallel(TurnOnShooterCommand());
    AddSequential(ArmBallCommand());
    AddSequential(WaitForShooterOnTargetCommand());
    AddSequential(FireBallCommand());
    AddSequential(WaitCommand(.5));
    AddSequential(ArmBallCommand());
    AddSequential(WaitForShooterOnTargetCommand());
    AddSequential(FireBallCommand());
    AddSequential(TurnOffShooterCommand());
  }

};
