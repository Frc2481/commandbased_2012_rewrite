
class Shooter : public PIDSubsystem() {
private:
  PIDController
  Jaguar* m_motor;
  Counter* m_sensor;
public:

  Shooter() : PIDSubsystem("Shooter", 0.001, 0.00001, 0, .01) {
    m_motor = new Jaguar(2);
    m_sensor = new Counter(3);

    GetController()->AbsoluteTolerance(50);
    GetController()->SetMinMaxInputRange(0, 6000);
    GetController()->SetMinMaxOutputRange(0, 1);
  }

  void setSpeed(double speed) {
    GetController()->SetSetpoint(speed);
  }

  void on() {
    GetController()->Enable();
  }

  void off() {
    GetController()->Disable();
  }

  bool isOnTarget() {
    return GetController()->IsOnTarget();
  }

protected:
  void writePIDOutput(float output) {
    m_motor->Set(output);
  }

  float readPIDInput() {
    return m_sensor->GetRate();
  }
};
