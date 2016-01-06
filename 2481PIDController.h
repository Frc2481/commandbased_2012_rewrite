
class RobotPIDInput {
public:
  virtual double readPIDInput() = 0;
};

class RobotPIDOutput {
public:
  virtual void writePIDOutput(double output) = 0;
};

class RoboPIDController {
private:
  double m_error;
  double m_maxoutput;
  double m_minoutput;
  double m_izone;
  double m_iaccum;
  double m_setpoint;

  double m_kp;
  double m_ki;
  double m_kd;

  int64_t m_prevTime;

  RobotPIDInput* m_input;
  RobotPIDOutput* m_output;

public:
  RoboPIDController(RobotPIDInput* input, RobotPIDOutput* output) {
    m_input = input;
    m_output = output;

    m_error = 0;
    m_maxoutput = 1.0;
    m_minoutput = -1.0;
    m_izone = -1;
    m_iaccum = 0;
    m_setpoint = 0;

    m_prevTime = 0;

    m_kp = m_ki = m_kd = 0;
  }

  void update() {

    //Null pointer check.
    if (m_input == 0) return;
    if (m_output == 0) return;

    double output = 0;

    //Error
    double error = m_setpoint - m_input->readPIDInput();

    //P
    double pOutput = m_kp * error;
    output += pOutput;

    //I
    m_iaccum += error;
    double iOutput = m_ki * m_iaccum;

    //I Zone Reset
    if (m_izone > 0 && error > m_izone) {
      iOutput = 0;
    }
    output += ioutput;

    //D
    double dOutput = 0;
    if (m_prevTime > 0) {
      double dt = FPGA::TimeStamp() - m_prevTime;
      double deriv = m_error - error) / dt;
      dOutput = m_kd * deriv;
      output += dOutput;
    }
    m_prevTime = FPGA::TimeStamp();

    SmartDashboard::putNumber("P_Output", pOutput);
    SmartDashboard::putNumber("I_Output", iOutput);
    SmartDashboard::putNumber("D_Output", dOutput);

    SmartDashboard::putNumber("PID_Output", output);

    m_output->writePIDOutput(output);
  }

  void setKP(double kp) {
    m_kp = kp;
  }

  void setKI(double ki) {
    m_ki = ki;
  }

  void setKD(double kd) {
    m_kd = kd;
  }

  double getKP() const {
    return m_kp;
  }

  double getKI() const {
    return m_ki;
  }

  double getKD() const {
    return m_kd;
  }

};
