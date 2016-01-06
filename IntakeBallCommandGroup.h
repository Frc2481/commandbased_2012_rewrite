
class IntakeBallCommandGroup : public CommandGroup {
public:

  IntakeBallCommandGroup() {
    AddSequential(new IntakeBallIntakeCommand());
    AddSequential(new IntakeBallLiftCommand());
  }
};
