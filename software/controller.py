import serial.tools.list_ports
import pygame
import time
import sys

pygame.init()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
serialInst = serial.Serial()


serialInst.baudrate = 9600
serialInst.port = "COM3" 
serialInst.open()

send_interval = 0.05
control_thresholds = [
    
    [lambda: joystick.get_axis(0) > 0.5, b"2\n", 0],
    [lambda: joystick.get_axis(0) < -0.5, b"-2\n", 0],
    [lambda: joystick.get_axis(1) > 0.5, b"3\n", 0],
    [lambda: joystick.get_axis(1) < -0.5, b"-3\n", 0],
    [lambda: joystick.get_button(10) and not joystick.get_button(9), b"-1\n", 0],
    [lambda: joystick.get_button(9) and not joystick.get_button(10), b"1\n", 0],
    ]
def check_time(control_item, current_time):
  condition, command, last_time = control_item
  if condition():
    if current_time - last_time >= send_interval:
      serialInst.write(command)
      control_item[2] = current_time

while True:
    for event in pygame.event.get():
        if event.type == pygame.JOYBUTTONDOWN:
            if event.button == 0:
                serialInst.write(b"exit\n")
                time.sleep(0.1)
                serialInst.close()
                sys.exit()
            elif event.button == 2:
                serialInst.write(b"reset\n")
    current_time = time.time()
    
    for item in control_thresholds:
        check_time(item, current_time)

    pygame.time.wait(10)