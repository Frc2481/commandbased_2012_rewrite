
class Lift : public Subsystem {

private:
  Jaguar* m_motor;
  DigitalInput* m_topSensor;
  DigitalInput* m_midSensor;

public:

  Lift() : Subsystem("Lift") {
    m_motor = new Jaguar(0);
    m_topSensor = new DigitalInput(0);
    m_midSensor = new DigitalInput(1);
  }

  bool isBallAtMidSensor() {
    return m_midSensor->Get();
  }

  bool isBallAtTopSensor() {
    return m_topSensor->Get();
  }

  void liftOnFwd() {
    m_motor->Set(1);
  }

  void liftOnRev() {
    m_motor->Set(-1);
  }

  void liftOff() {
    m_motor->Set(0);
  }
};
