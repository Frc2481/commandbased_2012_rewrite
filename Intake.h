
class Intake : public Subsystem {
private:
  Jaguar* m_motor;
  DigitalInput* m_bottomSensor;

public:

  Intake() : Subsystem("Intake") {
    m_motor = new Jaguar(1);
    m_bottomSensor = new DigitalInput(2);
  }

  bool isBallAtBottomSensor() {
    return m_bottomSensor->Get();
  }

  void onFwd() {
    m_motor->Set(1);
  }

  void onRev() {
    m_motor->Set(-1);
  }

  void off() {
    m_motor->Set(0);
  }

}
