#include "ArmBallCommand.h"
#include "FireBallCommand.h"
#include "VommitBallCommand.h"
#include "IntakeBallCommandGroup.h"
#include "TurnOnShooterCommand.h"
#include "TurnOffShooterCommand.h"

class JoystickButton;

class OI {
private:
  Joystick* m_driverStick;
  Joystick* m_auxStick;

  JoystickButton* m_armBallButton;
  JoystickButton* m_fireBallButton;
  JoystickButton* m_vommitBallButton;

  JoystickButton* m_intakeBallButton;

  JoystickButton* m_cancelIntakeButton;

  JoystickButton* m_turnOnShooterButton;
  JoystickButton* m_turnOffShooterButton;

  OI() {
    m_driverStick = new Joystick(0);
    m_auxStick = new Joystick(1);

    m_armBallButton = new JoystickButton(m_auxStick, 0);
    m_armBallButton->WhenPressed(new ArmBallCommand());

    m_fireBallButton = new JoystickButton(m_auxStick, 1);
    m_fireBallButton->WhenPressed(new FireBallCommand());

    m_vommitBallButton = new JoystickButton(m_auxStick, 2);
    m_vommitBallButton->WhileHeld(new VommitBallCommand());

    m_intakeBallButton = new JoystickButton(m_auxStick, 3);
    m_intakeBallButton->WhenPressed(new IntakeBallCommandGroup());

    m_cancelIntakeButton = new JoystickButton(m_auxStick, 4);
    m_cancelIntakeButton->WhenPressed(new CancelIntakeCommand());

    m_turnOnShooterButton = new JoystickButton(m_auxStick, 5);
    m_turnOnShooterButton->WhenPressed(new TurnOnShooterCommand());

    m_turnOffShooterButton = new JoystickButton(m_auxStick, 6);
    m_turnOffShooterButton->WhenPressed(new TurnOffShooterCommand());
  }
};
