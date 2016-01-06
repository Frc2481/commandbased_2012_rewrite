class GareeIntake : public Subsystem {
private:
  CATTalon* m_motor;
  Solenoid* m_Stow;
  Solenoid* m_Capture;

public:
  GareeIntake() : Subsystem("GareeIntake") {
    m_motor = new CATTalon(1);
    m_Stow = new Solenoid(2);
    new_Keep = new Solenoid(3);
  }

  bool isStowed() {
    return m_Stow->Get();
  }

  bool isCaptured() {
    return m_Capture->Get();
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

  void extendStow() {
    m_Stow->Set(1);
  }

  void retractStow() {
    m_Stow->Set(0);
  }

  void extendCapture() {
    m_Capture->Set(1);
  }

  void retractCapture() {
    m_Capture->Set(0);
  }

  double speed() {
    return m_motor->Get();
  }
}
